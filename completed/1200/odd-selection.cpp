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
        int n, x;
        cin >> n >> x;

        int oCount = 0, eCount = 0;
        
        while(n-->0) {
            int b;
            cin >> b;
            if (b % 2 == 0)
                eCount++;
            else oCount++;
        }

        if (oCount < 1)
            cout << "No" << endl;
        else {
            oCount = min(oCount, x);
            if (oCount % 2 == 0) oCount--;
            int need = x - oCount;
            if (eCount >= need)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
