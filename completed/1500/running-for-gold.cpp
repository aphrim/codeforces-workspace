//Category: 1500
//Link: https://codeforces.com/problemset/submission/1552/170673100
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> marathons(5, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> marathons[j][i];
            }
        }

        int best = 0;

        for (int i = 1; i < n; i++) {
            int c = 0;
            for (int m = 0; m < 5; m++) {
                c += marathons[m][i] < marathons[m][best];
            }
            
            if (c >= 3) {
                best = i;
            }
        }

        vector<int> counts(n);

        for (int m = 0; m < 5; m++) {
            for (int i = 0; i < n; i++) {
                counts[i] += marathons[m][best] < marathons[m][i];
            }
        }

        bool b = true;
        for (int i = 0; i < n; i++) {
            if (i != best && counts[i] < 3) b = false;
        }

        if (!b) cout << -1 << endl;
        else cout << best + 1 << endl;
    }
}
