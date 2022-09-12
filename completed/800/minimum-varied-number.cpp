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
        int s;
        cin >> s;

        int cur = 9;
        vector<int> out;
        while (s >= 10 || s > cur) {
            s -= cur;
            out.push_back(cur);
            cur--;
        }
        out.push_back(s);
        reverse(out.begin(), out.end());
        for (int n : out) cout << n;
        cout << endl;

    }
}
