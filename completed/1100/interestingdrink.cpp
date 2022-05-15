#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    vector<int> x, m;
    map<int, int> dp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        x.push_back(y);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        m.push_back(y);
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < q; i++) {
        int coins = m[i];
        if (dp[coins]) {
            cout << dp[coins] << '\n';
            continue;
        }

        auto loc = upper_bound(x.begin(), x.end(), coins); 

        if (coins < x[0]) {
            cout << 0 << '\n';
            dp[coins] = 0;
        } else if (coins > x.back()) {
            cout << n << '\n';
            dp[coins] = n;
        } else {
            cout << loc - x.begin() << '\n';
            dp[coins] = loc - x.begin();
        }



    }
}
