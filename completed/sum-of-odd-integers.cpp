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

        if ((n % 2 == 0 && k % 2 == 1) ||
            (n % 2 == 1 && k % 2 == 0) ||
            (k * k > n))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
};
