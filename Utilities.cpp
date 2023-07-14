#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;


// Input helper
void ri(int &n) { cin >> n; }
void ri(ll &n) { cin >> n; }
void ri(vi& a) {
    unsigned int length = a.size();
    for (unsigned int i = 0; i < length; i++) cin >> a[i];
}


// Output helper
void po(bool a) { cout << a << endl; }
void po(int a) { cout << a << endl; }
void po(long a) { cout << a << endl; }
void po(ll a) { cout << a << endl; }
void po_inl(int a) { cout << a; }
void po(vi& a) {
    for (auto i : a) cout << i << " ";
    cout << endl;
}

void solve() {
    int n = 0; ri(n);
    vi a(n); ri(a);
    po(a);
}

int main() {
    int num_of_tc = 1;
    ri(num_of_tc);

    for (unsigned int i = 0; i < num_of_tc; i++) {
        solve();
    }
    return 0;
}
