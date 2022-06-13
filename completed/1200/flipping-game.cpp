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

    for (int i = 0; i < n; i++) cin >> a[i];

    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n; j++) {
            c += a[j] == 1 ? -1 : 1;
            m = max(m, c);
        }
    }
    int ret = m;
    for (int x : a) if (x == 1) ret++;

    cout << ret << endl;

}
