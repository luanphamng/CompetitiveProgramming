#include <iostream>
using namespace std;

#define MAX_PROJECT 15
#define MAX_DATE 300

typedef struct {
    int start_date;
    int end_date;
} DATA;

int N;
DATA project_info[MAX_PROJECT];
bool selected[MAX_PROJECT];
bool mark[MAX_DATE + 1];
int maxProject;

void Data_Input(void) {
    cin >> N; // Input of number of projects
    // Input of project information
    for (int i = 0; i<N; i++) {
        cin >> project_info[i].start_date >> project_info[i].end_date;
    }
}

void resetMark() {
    for (int i = 0; i < MAX_DATE; ++i) {
        mark[i] = false;
    }
}
bool assignProject(int index) { // Tiến hành assign project thứ index cho Gram Park, trả ra false nếu không assign được
    for (int i = project_info[index].start_date; i <=
        project_info[index].end_date; ++i) {
        if (mark[i]) // Nếu ngày này đã được assigned vào một project nào đó
            return false; // Thì việc assign thêm project thứ index không được
        mark[i] = true; // Đánh dấu ngày thứ i đã được assign vào project index
    }
return true; // Assign thành công
}

int countProject() { // Đếm xem có bao nhiêu project được assign hợp lệ cho Gram Park
    int result = 0;
    resetMark(); // Đầu tiên chưa assign project nào, chưa có ngày nào bận
    for (int i = 0; i < N; ++i) {
        if (selected[i]) { // Nếu project i được chọn trong cấu hình, tiến hành assign project i cho Gram Park
        if (!assignProject(i)) // Nếu không assign được
            return -1; // Trả ra -1 với việc cấu hình không hợp lệ
        ++ result; // Sau khi assign thành công project thứ i, tăng số project lên 1.
        }
    }
    return result; // Trả ra số project của cấu hình hiện tại
}

void gen(int step) {
    if (step == N) {
        int projectCount = countProject();
        if (maxProject < projectCount)
            maxProject = projectCount;
        return;
    }
    for (int i = 0; i < 2; i++) {
        selected[step] = i == 1;
        gen(step + 1);
    }
}

int main() {
    Data_Input();
    maxProject = 0;
    gen(0);
    cout << maxProject;
    return 0;
}

