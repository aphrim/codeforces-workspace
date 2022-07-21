//Category: 1300
//Link: https://codeforces.com/problemset/problem/545/D
//Complexity O(n + nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q.begin(), q.end());

    int ret = 0, t = 0;

    for (int n : q) {
        if (t <= n) ret++;
        else continue;
        t += n;
    }
    cout << ret << endl;
}
