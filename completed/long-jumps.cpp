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
        int n;
        cin >> n;
        vector<int> dp(n, -1);
        vector<int> input;
        int ret = INT_MIN;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            input.push_back(x);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] < 0) {
                int x = i;
                int score = 0;
                while (x < n) {
                    if (dp[x] >= 0) {
                        score += dp[x];
                        break;
                    }
                    score += input[x];
                    x += input[x];
                }
                dp[i] = score;
                ret = max(ret, score);
            }
        }
        cout << ret << endl;

    }
}
