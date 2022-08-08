//Category: 1500
//Link: https://codeforces.com/problemset/problem/1352/E
//Complexity: O(n^2)
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

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        int ret = 0;

        for (int i = 0; i < n; i++) {
            int l = 0, r = 1, sum = a[0] + a[1], target = a[i];
            for (;;) {
                if (sum < target) {
                    r++;
                    if (r >= n) break;
                    sum += a[r];
                }

                if (sum > target) {
                    sum -= a[l];
                    l++;
                }

                if (sum == target) {
                    if ((i < l || i > r) && l < r) {
                        ret++;
                        break;
                    }
                    else {
                        sum -= a[l];
                        l++;
                    }
                }
            }
        }
        cout << ret << endl;
    }
}
