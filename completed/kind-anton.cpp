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
        vector<int> a, b;
        map<int, int> counts;
        bool ret = true;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            counts[x]++;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }


        for (int i = n - 1; i >= 0; i--) {
            int x = a[i]; 
            int y = b[i];
            counts[x]--;

            if (x < y)  ret = ret && counts[1] > 0;
            if (x > y) ret = ret && counts[-1] > 0;
        }

        if (ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
