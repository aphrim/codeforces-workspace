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

        if (n < 5) {
            cout << "NO" << endl;
            continue;
        }

        int d1 = 0, d2 = 0, d3 = 0;
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n % i == 0) {
                d1 = i;
                d2 = n / i;
                break;
            }
        }

        if (!d1) {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 2; i < sqrt(d1); i++) {
            if (d1 % i == 0 && i != d1 && i != d2 && d1 / i != d2) {
                d3 = d1 / i;
                d1 = i;
                break;
            }
        }

        if (!d3)
            for (int i = 2; i < sqrt(d2); i++) {
                if (d2 % i == 0 && i != d1 && i != d2 && d2 / i != d1) {
                    d3 = d2 / i;
                    d2 = i;
                    break;
                }
            }

        if (!d3) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << d1 << " " << d2 << " " << d3 << endl;
    }
}
