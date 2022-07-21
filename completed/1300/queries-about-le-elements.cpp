//Category: 1300
//Link: https://codeforces.com/problemset/problem/600/B
//Complexity: O(n + 2m + nlogn + 2mlogm)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(m), r;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    });

    int i = 0;

    for (pair<int, int> p : b) {
        while (i < n && p.first >= a[i]) i++;
        r.push_back({i, p.second});
    }

    sort(r.begin(), r.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    for (pair<int, int> p : r) {
        cout << p.first << " ";
    }
    cout << endl;

    cout << endl;
}
