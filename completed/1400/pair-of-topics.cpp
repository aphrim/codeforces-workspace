//Category: 1400
//Complexity: O(nlogn)
//Link: https://codeforces.com/problemset/problem/1324/D
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a, b, c;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        c.push_back(a[i] - b[i]);
    }

    sort(c.begin(), c.end());

    int ret = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] > 0) {
            int j = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
            ret += i - j;
        }
    }
    cout << ret << endl;

}
