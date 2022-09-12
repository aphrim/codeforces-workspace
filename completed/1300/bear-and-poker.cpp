#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x = 0;

    while (n--) {
        int y;
        cin >> y;
        while (y % 3 == 0 || y % 2 == 0) {
            if (y % 3 == 0) y /= 3;
            else y /= 2;
        }

        if (x == 0) x = y; 
        else if (x != y) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
