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

        int lp = 0, lc = 0;

        bool ret = true;
        while(n--) {
            int p, c;
            cin >> p >> c;
            int cp = p - lp, cc = c - lc;

            if (cc > cp || (cc < 0) || (cp < 0)) 
                ret = false;

            lc = c;
            lp = p;
        }

        if (ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
