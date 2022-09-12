//Link: https://codeforces.com/problemset/problem/330/B
//Category: 1300
//Complexity: O(n + m)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    n++;

    vector<bool>a(n);
    for (int i = 0; i < m; i++) {
        int d1, d2;
        cin >> d1 >> d2;
        a[d1] = true;
        a[d2] = true;
    }


    int center;
    for (int i = 1; i < n; i++) {
        if (!a[i]) center = i;
    }

    cout << n - 2 << endl;

    for (int i = 1; i < n; i++) {
        if (i != center) {
            cout << center << " " << i << '\n';
        }
    }
}
