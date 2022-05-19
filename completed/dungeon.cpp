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
        int x, y, z;
        cin >> x >> y >> z;

        int k = (x + y + z) / 9;
        if ((x + y + z) % 9 == 0 && x >= k && y >= k && z >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


    }
}
