//Category: 1300
//Link: https://codeforces.com/problemset/problem/1418/B
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
        vector<int> a(n), l(n), b;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (!l[i]) b.push_back(a[i]);
        }
        sort(b.begin(), b.end(), [](int a, int b) { return a > b; });
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!l[i]) a[i] = b[j++];
        }

        for (int n : a) cout << n << " ";
        cout << endl;

    }
}
