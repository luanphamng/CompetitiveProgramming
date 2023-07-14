#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

void ri(int &n) { cin >> n; }

void ri(vi& a) {
    unsigned int length = a.size();
    for (unsigned int i = 0; i < length; i++) cin >> a[i];
}

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

    if (n <= 1) {
        po(0);
        return;
    }

    ll local_result = (a[0] != a[1]);
    ll ans = local_result;

    for (int i = 0; i < n-2; i++) {
        if (a[i+1] == a[i+2]) {
            local_result = 0; // reset local result
        } else if ((a[i+2] - a[i+1]) * (a[i] - a[i+1]) > 0) {
            local_result++; // zigzag extended
        } else {
            local_result = 1; // zigzag broken, new zigzag started
        }
        ans += local_result;
    }
    po(ans);
}


#define CALC_ANS_MACRO(lo, hi) (1LL * (hi-lo) * (hi-lo-1) / 2)
void solve2() {
    int n = 0; ri(n);
    vi a(n); ri(a);

    if (n <= 1) {
        po(0); return;
    }

    int lo = 0, hi = 0;
    ll ans = 0;

    while (hi < n) {
        if (lo == hi) {
            hi++;
            continue;
        }

        if (a[hi-1] < a[hi]) {
            if (hi-lo == 1 || a[hi-2] > a[hi-1]) {
                hi += 1;
            } else {
                ans += CALC_ANS_MACRO(lo, hi);
                lo = hi - 1;
            }
        } else if (a[hi-1] > a[hi]) {
            if (hi-lo == 1 || a[hi-2] < a[hi-1]) {
                hi += 1;
            } else {
                ans += CALC_ANS_MACRO(lo, hi);
                lo = hi - 1;
            }
        } else {
            ans += CALC_ANS_MACRO(lo, hi);
            lo = hi;
        }
    }

    ans += CALC_ANS_MACRO(lo, hi);
    po(ans);
}

int main() {
    int num_of_tc = 1;
    ri(num_of_tc);

    for (unsigned int i = 0; i < num_of_tc; i++) {
        solve2();
    }
    return 0;
}
