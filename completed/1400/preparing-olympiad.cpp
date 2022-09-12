//Category: 1400
//Complexity: O(2 ^ n), bitmask combination enumarations.
//Link: https://codeforces.com/problemset/problem/550/B
//Learned alot about bitmask combination enumeration doing this problem, a bit hard for a 1400 though.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, r, x, ret = 0;
    cin >> n >> l >> r >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int mask = 0; mask < (1 << a.size()); mask++) {
        vector<int> comb;

        for (int i = 0; i < a.size(); i++) {
            if (mask & (1 << i)) {
                comb.push_back(a[i]); 
            }
        }

        if ((comb.size() > 1) && comb.back() - comb[0] >= x) {
            int sum = 0;
            for (int z : comb) sum += z;
            if (sum >= l && sum <= r) ret++;
        }
    }

    cout << ret << endl;
}
