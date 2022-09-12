//Category: 1500
//Link: https://codeforces.com/problemset/problem/1304/C
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

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;

        int maT = m, miT = m, t = 0;
        bool flag = true;
        while(n--) {
            int ti, li, hi;
            cin >> ti >> li >> hi;
            maT += ti - t, miT -= ti - t;
            if (maT < li || miT > hi) {
                flag = false;
                while (n--) {
                    cin >> ti >> li >> hi;
                }
                break;
            }

            t = ti;
            maT = min(maT, hi);
            miT = max(miT, li);
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
