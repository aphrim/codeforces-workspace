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
        int n, m;
        cin >> n >> m;
        if (n == 1) {
            if (m % 2 == 1) {
                cout << "Tonya" << endl;
            } else {
                cout << "Burenka" << endl;
            }
            continue;
        }
        if (n % 2 == 0) {
            if (m % 2 == 0) {
                cout << "Tonya" << endl;
            } else
                cout << "Burenka" << endl;
            continue;
        }
        if (m % 2 == 1) {
            cout << "Tonya"<< endl;
        } else cout << "Burenka" << endl;
    }
}
