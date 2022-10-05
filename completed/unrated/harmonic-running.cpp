//Solution for a problem I came up with myself.
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
        int n, a, b;
        cin >> n >> a >> b;

        //Converted to mph
        float pa = n / a;
        float pb = n / b;

        cout << (int) (2 / (1 / pa + 1 / pb)) << endl;
    }
}
