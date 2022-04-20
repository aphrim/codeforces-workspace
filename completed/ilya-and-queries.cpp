#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int m;
    cin >> s >> m;
    int n = s.size() - 1;
    vector<int> prefixSum{0};

    for (int i = 0; i < n; i++) {
        prefixSum.push_back(prefixSum.back() + (s[i] == s[i + 1] ? 1 : 0));
    }

    while(m-->0) {
        int l, r, ans = 0;
        cin >> l >> r;
        ans += prefixSum[r - 1] - prefixSum[l - 1];

        cout << ans << endl;
    }

}
