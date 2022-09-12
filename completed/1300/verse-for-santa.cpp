//Category: 1300
//Link: https://codeforces.com/problemset/problem/1279/B
//Complexity: O(n)
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
        int n, s, m = 0;
        cin >> n >> s;
        vector<int> a(n), prefixSum(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) prefixSum[0] = a[i];
            else prefixSum[i] = prefixSum[i - 1] + a[i];
            if (prefixSum[i] <= s) m = i;
        }
        
        if (prefixSum.back() <= s) {
            cout << 0 << endl;
            continue;
        }


        int elToRem = max_element(a.begin(), min(a.begin() + m + 2, a.end())) - a.begin();
        cout << elToRem + 1 << endl;
    }
}
