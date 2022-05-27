//Category: 1300
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1555/C
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
        int m;
        cin >> m;
        vector<int> topRow(m), bottomRow(m);

        for (int i = 0; i < m; i++) cin >> topRow[i];
        for (int i = 0; i < m; i++) cin >> bottomRow[i];

        int ret = INT_MAX;

        int sumTop = 0, sumBottom = 0;

        for (int n : topRow) sumTop += n;

        for (int i = 0; i < m; i++) {
            sumTop -= topRow[i];
            ret = min(ret, max(sumTop, sumBottom));
            sumBottom += bottomRow[i];
        }

        cout << ret << endl;
    }
}
