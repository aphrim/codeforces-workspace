//Category: 1300
//Link: https://codeforces.com/problemset/problem/1307/B
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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        cin >> a;

        bool b = false;
        for (int y : a) {
            if (y == x) b = true;
        }

        if (b) cout << 1 << endl;
        else cout << max((int64_t)2, (int64_t) ceil(double(x) / *max_element(a.begin(), a.end()))) << endl;
    }
}
