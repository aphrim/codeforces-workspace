//Link: https://codeforces.com/problemset/problem/1618/D
//Category: 1300
//Complexity: O(nlogn)
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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> numerators = vector<int>(a.begin() + (n - 2 * k), a.begin() + (n - k));
        vector<int> denoms = vector<int>(a.begin() + (n - k), a.end());

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += numerators[i] / denoms[i]; 
        }

        for (int i = 0; i < (n - 2 * k); i++) sum += a[i];

        cout << sum << '\n';
    }
}
