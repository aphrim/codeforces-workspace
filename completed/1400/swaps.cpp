//Category: 1400
//Link: https://codeforces.com/problemset/problem/1573/B
//Complexity: O(n)
//This took me like 3 hours to come up with wtf 
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
        vector<int> a(n), b(n);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[(x-1) / 2] = i;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b[(x-1) / 2] = i;
        }

        int ret = INT_MAX, cur = INT_MAX;

        for (int i = 0; i < n; i++) {
            cur = min(cur, a[i]);
            ret = min(ret, cur + b[i]);
        }

        cout << ret << endl;
    }
}
