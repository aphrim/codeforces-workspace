//Category: 1400
//Time Complexity: Complicated 
//Link: https://codeforces.com/problemset/problem/1350/B
//Note: In count function, didn't realise that i was 1-indexed in the problem, so 1 is subtracted it except for in the loop.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

vector<int> models;
vector<int> dp;

int count(int i) {
    int ret = 1;
    int last = models[i - 1];
    if (dp[i - 1] > 0)
        return dp[i - 1];
    for (int j = i * 2; j <= models.size(); j += i) {
        if (models[j - 1] > last)
            ret = max(ret, count(j) + 1);
    }
    dp[i - 1] = ret;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dp = vector<int>(n, -1);
        models = vector<int>(n);

        for (int i = 0; i < n; i++) cin >> models[i];

        int ret = 1;
        for (int i = n; i >= 1; i--) {
            ret = max(ret, count(i));
        }
        cout << ret << endl;
    }
}
