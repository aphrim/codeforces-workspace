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
        bool inc = true;
        int changes = 0;
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] > 0) {
                if (!inc) {
                    inc = true;
                    changes++;
                }
            } else if (a[i] - a[i-1] < 0) {
                if (inc) {
                    inc = false;
                    changes++;
                }
            }
        }

        if (changes > 1) {
            cout << "NO" << endl;
        } else cout << "YES" << endl;
    }
}
