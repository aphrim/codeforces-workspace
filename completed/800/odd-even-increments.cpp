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
        int x;
        cin >> x;
        bool o = false;

        vector<int> o1, o2;
        while (x-->0) {
            int n;
            cin >> n;
            if (o)
                o1.push_back(n);
            else
                o2.push_back(n);
            o = !o;
        }

        int p1 = o1[0] % 2 == 0;
        int p2 = o2[0] % 2 == 0;
        bool ret = true;

        for (int n : o1) {
            if (n % 2 == 0 != p1) {
                ret = false;
                break;
            }
        }

        for (int n : o2) {
            if (n % 2 == 0 != p2) {
                ret = false;
                break;
            }
        }

        if (ret)
            cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
