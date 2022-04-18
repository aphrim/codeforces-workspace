#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;
    t--;

    vector<int> a;

    while(n-->1) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int i = 0;
    for(;;) {
        if (i == t) {
            cout << "YES" << endl;
            break;
        }

        if (i >= a.size()) {
            cout << "NO" << endl;
            break;
        }

        i += a[i];
    }
    
}
