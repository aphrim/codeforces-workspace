#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, n = 0;
    cin >> x;


    while (x) {
        n += x & 1;
        x >>= 1;
    }

    cout << n << endl;
}
