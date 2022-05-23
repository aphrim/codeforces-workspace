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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), [](int a, int b) {
            return a < b;
        });

        int ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            int y = a[i], c = 1; 
            while (y < x) {
                if (i <= 0) break;
                y = a[--i] * ++c;
            }
            if (y < x) break;
            ret++;
        }
        cout << ret << endl;
    }
};
