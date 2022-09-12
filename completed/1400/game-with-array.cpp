//Category: 1400
//Link: https://codeforces.com/problemset/problem/1355/D
//Complexity: O(n - 1) (For printing answer, calcing is O(1))
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    if (n <= s / 2) {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++) {
                cout << 1 << " ";
        }
        cout << s - n + 1 << endl;
        cout << s / 2 << endl;
    } else cout << "NO" << endl;
}
