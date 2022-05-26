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
        while (n--) {
            int x;
            cin >> x;
            a.push_back(x);
            b.push_back(x);
        }


        sort(b.begin(), b.end());
        int m = *min_element(a.begin(), a.end());
        bool ret = true;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] != b[i] && a[i] % m != -1) {
                ret = false; 
            }
        }

        if (ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        
    }
}
