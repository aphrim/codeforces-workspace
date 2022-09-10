//Category: 1500
//Link: https://codeforces.com/problemset/problem/1301/B
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
        vector<int>a(n);
        cin >> a;

        int minN = 10000000000, maxN = 0, last = a[0];

        if (last != -1 && a[1] == -1) {
            minN = min(minN, last);
            maxN = max(maxN, last);
        }

        for (int i = 1; i < n; i++) {
            int x = a[i]; 
            if (x == -1) {
                if (last != -1) {
                    minN = min(minN, last);
                    maxN = max(maxN, last);
                }
            } else {
                if (last == -1) {
                    minN = min(minN, x);
                    maxN = max(maxN, x);
                }
            }
            last = x;
        }

        if (minN == 10000000000) {
            cout << 0 << " " << 69 << endl;
            continue;
        }
        int k = (maxN + minN) / 2, m = 0;
        if (a[0] == -1) a[0] = k;
        for (int i = 1; i < n; i++) {
            if (a[i] == -1) a[i] = k;
            m = max(m, abs(a[i] - a[i-1]));
        }

        cout << m << " " << k << endl;
    }
}
