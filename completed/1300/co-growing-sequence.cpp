//Category: 1300
//Link: https://codeforces.com/problemset/problem/1547/D
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
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b {0};
        for (int i = 0; i < n; i++) cin >> a[i];
        
        for (int i = 1; i < n; i++) {
            int last = a[i-1] ^ b[i-1];
            std::bitset<32> bi;
            for (int j = 0; j < 32; j++) {
                if (last & (1<<j)) {
                    if (!(a[i] & (1<<j)))
                        bi[j] = 1;
                } else {
                    if (a[i] & (1<<j))
                        bi[j] = 0;
                }
            }
            b.push_back(bi.to_ulong());
        }

        for (int x : b) cout << x << " ";
        cout << endl;

    }
}
