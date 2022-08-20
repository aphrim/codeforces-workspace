//Category: 1500
//Link: https://codeforces.com/problemset/problem/1400/C
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
        string s;
        int x;
        cin >> s >> x;
        int n = s.size();
        string w(n, '1');

        for (int i = 0; i < n; i++)
            if (s[i] == '0') {
                if (i + x < n)
                    w[i + x] = '0';
                if (i >= x)
                    w[i - x] = '0';
            }


        bool b = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && !((i >= x && w[i-x] == '1') || (i < n - x && w[i+x] == '1')))
                b = false;
        }

        if (b)
            cout << w << endl;
        else
            cout << -1 << endl;
    }
}
