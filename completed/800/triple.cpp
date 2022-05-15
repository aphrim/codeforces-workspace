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
        int n;
        cin >> n;

        map<int, int> counts;

        while (n-->0) {
            int x;
            cin >> x;
            counts[x]++;
        }

        bool found = false;
        for (auto it : counts) {
            if (it.second >= 3) {
                cout << it.first << endl;
                found = true;
                break;
            }
        }

        if (not found)
            cout << -1 << endl; 
    }
}
