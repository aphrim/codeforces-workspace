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
        int n, k;
        cin >> n >> k;

        bool res = true;
        for (int i = 0; i < n / 2; i++) {
            int x = i * 2 + 1, y = i * 2 + 2;
            if (((x + k) * y) % 4 == 0 || ((y + k) * x % 4) == 0) {} else res = false;
        }

        if (res) {
            cout << "YES" << endl;
            for (int i = 0; i < n / 2; i++) {
                int x = i * 2 + 1, y = i * 2 + 2;
                if (((x + k) * y) % 4 == 0) 
                    cout << x << " " << y << endl;
                else
                    cout << y << " " << x << endl;
            }
        }
        else cout << "NO" << endl;
    }
}
