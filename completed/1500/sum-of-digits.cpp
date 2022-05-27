//Category: 1500
//Complexity: ~O(log10 n), in the worst case, the while loop should have at most log10(n) iterations.
//Link: https://codeforces.com/problemset/problem/1409/D
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int sumOfDigits(int n) {
    int ret = 0;
    while (n >= 1) {
        ret += n % 10;
        n /= 10;
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
        int n, s;
        cin >> n >> s;
        int ret = 0, mult = 1;
        
        while (sumOfDigits(n) > s) {
            if (n % 10 > 0) {
                ret += (10 - (n % 10)) * mult;
                n += 10;
            }
            n /= 10;
            mult *= 10;
        }

        cout << ret << endl;
    }
}
