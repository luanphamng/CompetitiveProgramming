  
#include <iostream>
#include <cstring>

using namespace std;

#define LOGNL(text, num) cout << text << ": " << num << endl;
#define LOG(text, num) cout << text << ": " << num << "   ";

int N;        //Day
int S;        //Storage cost
int C[50010]; //Price
int Y[50010]; //Capacity
int notBuyDay[50010];

void Input_Data(void)
{
    cin >> N >> S;
    for (long i = 0; i < N; i++)
    {
        cin >> C[i] >> Y[i];
    }
}

string int2String(unsigned long long r)
{
    string rs;
    while (r > 0)
    {
        rs += (char)(r % 10 + '0');
        r /= 10;
    }
    return rs;
}

string add2BigInt(string num1, string num2) {
    string rs;    
    int len1 = num1.length();
    int len2 = num2.length();
    int maxLen = max(len1, len2);

    for (int i = 0; i < maxLen; i++) {
        if (i >= len1)
            num1.push_back('0');
        if (i >= len2)
            num2.push_back('0');
    }

    LOG("Num1", num1);
    LOGNL("Num2", num2);
    int sum = 0;
    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        rs.push_back((sum%10) + '0');
        carry = sum/10;
    }
    if (carry != 0) {
        rs.push_back(carry + '0');
    }
    return rs == "" ? "0" : rs;
}

string MinimalCost()
{
    memset(notBuyDay, 0, sizeof notBuyDay);
    if (N == 1) {
        return int2String(C[0] * Y[0]);
    }
    long long cost = 0;
    string rs = "";

    // Calculate cost
    // Must buy on day 1
    cost = C[0] * Y[0];
    rs = int2String(cost);    
    long buyDay = 0;
    for (long i = 1; i < N; i++)
    {
        if ((C[i] - C[buyDay]) > (S * (i - buyDay) ))
        { // price high then previous days. Don't buy on this day, buy on previous day
            notBuyDay[i] = -1;            
            continue;
        }
        buyDay = i;
    }

    long preLowCostDay = 0;
    for (long i = 1; i < N; i++)
    {
        if (notBuyDay[i] == -1)
        { // the day don't buy
            long diffDay = i - preLowCostDay;
            cost = S * (diffDay)*Y[i] + C[preLowCostDay] * Y[i];
        }
        else
        {
            preLowCostDay = i;
            cost = C[i] * Y[i];
        }
        rs = add2BigInt(int2String(cost), rs);
    }
    return rs;
}

void printStringRevs(string a) {
    int len = a.length();
    for (int i = len - 1; i >= 0; i--)
    {
        cout << a[i];
    }
}
int main()
{
    string ans = "-1";
    freopen("factory.inp", "r", stdin);
    Input_Data(); //Input function

    // TODO : Write your codes.
    ans = MinimalCost();    
    printStringRevs(ans);
    return 0;
}