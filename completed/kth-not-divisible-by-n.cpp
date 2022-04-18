#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t-->0) {
        int n, k;

        cin >> n >> k;

        cout << (k - 1) / (n - 1) + k << endl;
    }

}
