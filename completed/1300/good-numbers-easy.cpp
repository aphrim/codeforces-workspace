//Category: 1300
//Link: https://codeforces.com/problemset/problem/1249/C1
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

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

        set<int> powersUsed;
        for (int i = 9; i >= 0; i--) {
            if (pow(3, i) <= n) {
                powersUsed.insert(i);
                n -= pow(3, i);
            }
        }

        for (int i = 0; i < 11; i++) {
            if (powersUsed.count(i) == 0 && pow(3, i) >= n) {
                powersUsed.insert(i);
                break;
            }
        }

        int ret = 0;

        for (int i = 0; i < 11; i++) {
            ret += powersUsed.count(i) * pow(3, i);
        }

        for (int i = 10; i >= 0; i--) {
            if (ret - pow(3, i) >= nn) ret -= pow(3, i);
        }

        cout << ret << endl;

    }
}
