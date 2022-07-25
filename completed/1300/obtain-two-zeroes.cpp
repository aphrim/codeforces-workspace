//Category: 1300
//Link: https://codeforces.com/problemset/problem/1260/B
//Complexity: O(1)
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
        int a, b;
        cin >> a >> b;

        if ((a + b) %  3 == 0 && min(a,b) * 2 >= max(a,b))
            cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
