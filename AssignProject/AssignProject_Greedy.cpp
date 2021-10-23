#include <iostream>
using namespace std;
#define MAX_PROJECT (15)
typedef struct
{
    int start_date;
    int end_date;
} DATA;

int N;
DATA project_info[MAX_PROJECT];
void Data_Input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> project_info[i].start_date >> project_info[i].end_date;
    }
}
int Solve(void)
{
    int cnt = 0;
    int lastend = -1; // Ban đầu tiên chưa có dự án nào được chọn, thời gian kết thúc của dự án gần nhất là - 1.
    for(int i = 0; i < N; i++)
    {
        if (lastend < project_info[i].start_date)
        { // Nếu thời gian bắt đầu của dự án thứ i mà lớn hơn thời gian kết thúc của dự án gần nhất
                lastend = project_info[i].end_date; // Assign dự án cho Gram Park, update thời gian kết thúc của dự án gần nhất
                                  cnt++; // Tăng số dự án được assgin lên
        }
    }
    return cnt;
}
void Sorting(void)
{
    int i, j;
    DATA temp;
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (project_info[j].end_date > project_info[j +
                                                        1]
                                               .end_date)
            {
                temp = project_info[j];
                project_info[j] = project_info[j + 1];
                project_info[j + 1] = temp;
            }
        }
    }
}
int main(void)
{
    int sol = 0;
    Data_Input();
    Sorting(); // Sắp xếp các projects theo thứ tự tăng dần thời gian kết thúc
    sol = Solve();
    cout << sol << endl;
    return 0;
}