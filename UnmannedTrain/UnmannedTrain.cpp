// PASSED on 20/10/2021
#include <iostream>
#include <list>

struct Point {
    int x;
    int y;
};

using namespace std;
int M, N;
int area[50][50];

Point firstPoint = {-1, -1};

int neighborX[4] = {-1, 0, 1, 0};
int neighborY[4] = {0, 1, 0, -1};
list<Point> allRegion1;


void input() {
    // freopen("unmamnedTrain.inp", "r", stdin);
    cin >> M; cin >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
        }
    }
}

bool isValidCoor(int x, int y) {
    return ((x >= 0) && (x < M) && (y >= 0) && (y < N));
}

void fillFirstRegion() {
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j++) {
            if (area[i][j] == 1) {
                firstPoint = {i, j};
                break;
            }
            if (firstPoint.x != -1) break;
        }
    }

    // start fill first region
    list<Point> nextVisit; nextVisit.push_front(firstPoint);
    allRegion1.push_back(firstPoint);
    while (!nextVisit.empty()) {
        Point ptCurrent = nextVisit.front();
        area[ptCurrent.x][ptCurrent.y] = 2;
        nextVisit.pop_front();

        for (int i = 0; i < 4; i ++) {
            int _neighborX = ptCurrent.x + neighborX[i];
            int _neighborY = ptCurrent.y + neighborY[i];

            if (isValidCoor(_neighborX, _neighborY) && area[_neighborX][_neighborY] == 1) {
                nextVisit.push_front({_neighborX, _neighborY});
                allRegion1.push_back({_neighborX, _neighborY});
            }
        }
    }

}

int findMinDistance() {
    int _neighborX, _neighborY;

    while (!allRegion1.empty()) {
        Point ptCurrent = allRegion1.front();
        allRegion1.pop_front();

        for (int i = 0; i < 4; i ++) {
            _neighborX = ptCurrent.x + neighborX[i];
            _neighborY = ptCurrent.y + neighborY[i];

            if (isValidCoor(_neighborX, _neighborY)) {
                if (area[_neighborX][_neighborY] == 1) {
                    return area[ptCurrent.x][ptCurrent.y] - 2;
                } else if (area[_neighborX][_neighborY] == 0) {
                    allRegion1.push_back({_neighborX, _neighborY});
                    area[_neighborX][_neighborY] = area[ptCurrent.x][ptCurrent.y] + 1;
                    // cout << "Change point at: " <<_neighborX << ", " << _neighborY << " to " << area[ptCurrent.x][ptCurrent.y] + 1 << endl;
                    // cout << endl <<"Print array: " << endl;
                    // for (int i = 0; i < M; i++) {
                    //     for (int j = 0; j < N; j++) {
                    //         cout << area[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }
                } else {
                }

            }
        }
    }

    return area[_neighborX][_neighborY] - 1;
}

int main() {
    input();

    fillFirstRegion();
    // // cout << endl <<"Print array after fill: " << endl;
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << area[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int result = findMinDistance();
    cout << result;

    return 0;
}