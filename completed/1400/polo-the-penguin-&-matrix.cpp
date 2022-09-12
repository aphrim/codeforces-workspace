//Category: 1400
//Complexity: O(n), O(nlogn) if including sorting.
//Link: https://codeforces.com/problemset/problem/289/B
//Pretty nice and easy problem. Note: Just find the median, and change everything to median.

#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n * m);

    for (int i = 0; i < n * m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int median = a[a.size() / 2];

    int ret = 0;

    for (int x : a) {
        if (abs(x - median) % d != 0) {
            cout << -1;
            return 0;
        }

        ret += abs(x - median) / d;
    }

    cout << ret << endl;

}
