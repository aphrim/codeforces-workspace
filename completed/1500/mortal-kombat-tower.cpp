//Category: 1500
//Link: https://codeforces.com/problemset/problem/1418/C
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
        vector<int> a(n);
        cin >> a;
        
        int ret = 0, l = 0;
        for (int i = 1; i < n; i++) {
            l += a[i];
            if (a[i] == 0) {
                ret += l / 3;
                l = 0;
            }
        }
        ret += l / 3 + a[0];
        cout << ret << endl;
    }
}
