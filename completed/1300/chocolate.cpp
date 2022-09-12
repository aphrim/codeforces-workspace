//Category: 1300
//Link: https://codeforces.com/problemset/problem/617/B
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int right = 0, left = 0, ret = 1, so = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right += a[i];
    }

    if (right == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (left == 1) so++; 
        left += a[i];
        right -= a[i];
        if (left != 1) {
            if (left > 1)
                ret *= so - 1;
            so = 1;
            left = a[i];
        }
    }

    cout << ret << endl;





}
