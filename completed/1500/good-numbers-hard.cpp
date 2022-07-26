//Category: 1500
//Link: https://codeforces.com/contest/1249/problem/C2
//Complexity: O(1)
//Super proud of my O(1) solution! It is alot of code, but is suprising fast even for the biggest of numbers, passes all testcases in 15ms!, official solution is O(logn)
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int pow3(int x) {
    int ret = 1;
    for (int i = 0; i < x; i++) {
        ret *= 3;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, nn;
        cin >> n;
        nn = n;

        vector<bool> powersUsed(41);
        for (int i = 39; i >= 0; i--) {
            if (pow3(i) <= n) {
                powersUsed[i] = true;
                n -= pow3(i);
            }
        }

        for (int i = 0; i < 40; i++) {
            if (!powersUsed[i] && pow(3, i) >= n) {
                powersUsed[i] = true;
                break;
            }
        }

        int ret = 0;

        for (int i = 0; i < 40; i++) {
            ret += powersUsed[i] * pow(3, i);
        }

        for (int i = 39; i >= 0; i--) {
            if (powersUsed[i]) {
                if (ret - pow3(i) >= nn) {
                    ret -= pow3(i);
                    powersUsed[i] = false;
                }
            }
        }

        ret = 0;

        for (int i = 0; i < 40; i++) {
            if (powersUsed[i]) {
                ret += pow3(i);
            }
        }

        cout << ret << endl;

    }
}
