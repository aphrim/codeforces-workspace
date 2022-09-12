//Category: 1300
//Link: https://codeforces.com/problemset/problem/1638/C
//Complexity: O(nlogn)
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
        vector<int> a(n);
        vector<pair<int, int>> minPositions(n);
        cin >> a;

        for (int i = 0;  i < n; i++) {
            minPositions[i] = {a[i], i};
        }
        sort(minPositions.begin(), minPositions.end());

        int lmax = a[0], rmin = 0, ret = 1;
        if (0 == minPositions[rmin].second && n > 1) rmin = 1;
        
        for (int i = 1; i < n; i++) {
            if (lmax > minPositions[rmin].first) {
                lmax = max(lmax, a[i]);
            } else {
                ret++;
                lmax = a[i];
            }
            while (minPositions[rmin].second <= i && rmin < n - 1) rmin++;
        }

        cout << ret << endl;
    }
}
