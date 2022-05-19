#include <bits/stdc++.h>
#define int long long int

using namespace std;

bool solve(bool even, int k, int n) {
    if (even) {
        int s = (k - 1) * 2;
        int rem = n - s;
        if (rem > 0 && rem % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << rem << endl;
            return true;
        } else {
            return false;
        }
    } else {
        int s = (k - 1);
        int rem = n - s;
        if (rem > 0 && rem % 2 == 1) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << 1 << " ";
            }
            cout << rem << endl;
            return true;
        } else {
            return false;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-->0) {
        int n, k;
        cin >> n >> k;
        
        if (n - k + 1 <= 0) {
            cout << "NO" << endl;
            continue;
        }

        if (!solve(true, k, n))
            if (!solve(false, k, n)) 
                cout << "NO" << endl;
    }
}
