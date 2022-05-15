//Category: 1300
//Complexity O(n)
//Link: https://codeforces.com/problemset/problem/189/A
//Note: Dp[i] contains the max cuts up the ribbon from 0 to i.
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[n + 1];
    fill(dp, dp + n + 1, -1e10);
    dp[0] = 0;
    for (int i = a; i <= n; i++) dp[i] = max(dp[i], dp[i - a] + 1);
    for (int i = b; i <= n; i++) dp[i] = max(dp[i], dp[i - b] + 1);
    for (int i = c; i <= n; i++) dp[i] = max(dp[i], dp[i - c] + 1);

    cout << dp[n] << endl; 
}
