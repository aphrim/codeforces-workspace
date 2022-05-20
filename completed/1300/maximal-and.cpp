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
        int n, k;
        cin >> n >> k;

        vector<int> bitCounts(31);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 31; j++) {
                if (x & (1 << j)) bitCounts[j]++;
            }
        }

        int ret = 0;
        for (int i = 30; i >= 0; i--) {
            if (n - bitCounts[i] <= k) {
                k -= n - bitCounts[i];
                ret += (1 << i);
            }
        }
        cout << ret << endl;
    }
}
