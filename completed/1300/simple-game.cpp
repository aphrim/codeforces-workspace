//Category: 1300
//Link: https://codeforces.com/problemset/problem/570/B
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int half = n / 2;
    int ans;
    if (m > half) ans = m - 1;
    else ans = m + 1;
    cout << ans << endl;
}
