#include <iostream>
#include <cstring>
#include <list>

using namespace std;

const int iMAX = 100;
int N;
char area[iMAX][iMAX];
char iVisited[iMAX][iMAX];

int neighborX[4] = {1, 0, -1, 0};
int neighborY[4] = {0, 1, 0, -1};

struct Point {
    int x;
    int y;
};

void Input() {
    freopen("roadconstruct.inp", "r", stdin);
    char n; cin >> n;
    N = (int) n - '0';
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            area[i][j] = s[j] /*- '0'*/;
        }
    }
}

// 041 041
// 253 253
// 620 620

int getValue(int x, int y) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N))
        return -1; // invalid point
    return area[x][y] - '0';
}

bool checkIsVisited(int x, int y) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) {
        return true;
    }
    return iVisited[x][y];
}

int Solve() {
    list<Point> vt;
    vt.push_front({0, 0});
    iVisited[0][0] = true;

    while (!vt.empty()) {
        Point currCheck = vt.front();
        iVisited[currCheck.x][currCheck.y] = true;
        vt.pop_front();
        for (int i = 0; i < 4; i++) {
            int nextX = currCheck.x + neighborX[i];
            int nextY = currCheck.y + neighborY[i];
            if (getValue(nextX, nextY) != -1) { // Valid point
                int leftValue = (getValue(nextX, nextY - 1) == -1) ? 0 : getValue(nextX, nextY - 1);
                int upValue = (getValue(nextX - 1, nextY) == -1) ? 0 : getValue(nextX - 1, nextY);

                // up and left had => calc and save this to queue
                if (checkIsVisited(nextX, nextY - 1) && checkIsVisited(nextX - 1, nextY)) {
                    if (!checkIsVisited(nextX, nextY)) {
                        vt.push_front({nextX, nextY});
                        area[nextX][nextY] += ((leftValue < upValue) ? leftValue : upValue);
                        cout << "Add new to list: " << nextX << ", " << nextY << endl;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
    return area[N-1][N-1];
}

int main() {
    memset(&iVisited, 0x00, sizeof(iVisited));
    Input();

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << area[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "Result: " << endl << Solve();
    return 0;
}