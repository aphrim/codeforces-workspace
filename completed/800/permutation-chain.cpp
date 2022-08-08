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
        for (int i = 1; i <= n; i++) a[i-1] = i;

        cout << n << endl;
        cout << a << endl;
        for (int i = 0; i < n - 1; i++) {
            if (i == 0) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            } else {
                int tmp = a[i - 1];
                a[i - 1] = a[i + 1];
                a[i + 1] = tmp;
            }
            cout << a << endl;
        }
    }
}
