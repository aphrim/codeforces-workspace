//Category: 1400
//Complexity: O(1) if not including O(n) for getting input.
//Link: https://codeforces.com/problemset/problem/1375/C
//Note: True if first < last
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

        int f, l;
        cin >> f;
        l = f;
        n--;

        while(n--) {
            cin >> l;
        }

        if (f < l) 
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
