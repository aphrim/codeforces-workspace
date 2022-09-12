//Category: 1300
//Link: https://codeforces.com/problemset/problem/1615/B
//Complexity: O(n); n is max possible r value, in this case 2 * 10 ^ 5
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> prefix(200003);

    for (int i = 0; i < 200003; i++) {
        if (i == 0) prefix[i] = vector<int>(30);
        else {
            prefix[i] = vector<int>(30);
            for (int j = 0; j < 30; j++) {
                prefix[i][j] = prefix[i-1][j] + ((i & (1 << j)) ? 1 : 0);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        vector<int> counts(30);
        cin >> l >> r;

        for (int i = 0; i < 30; i++) {
            counts[i] = prefix[r][i] - prefix[l - 1][i];
        }

        int maxCount = 0;
        for (int n : counts) {
            maxCount = max(maxCount, n);
        }

        cout << (r - l + 1) - maxCount << endl;
    }
}
