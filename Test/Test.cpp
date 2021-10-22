#include <iostream>
using namespace std;

int main() {
    bool x;
    for (int i = 0; i < 2; i++) {
        x = i == 1;
        cout << "x = " << x << endl;
    }
    return 0;
}