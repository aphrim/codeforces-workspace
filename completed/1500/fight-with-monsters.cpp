//Category: 1500
//Link: https://codeforces.com/problemset/problem/1296/D
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x;
    
        if (x <= a) c = 0;
        else {
            if (a + b >= x) c = ceil(x / (float) a) - 1;
            else {
                int rem = x % (a + b);
                if (rem == 0)
                    c = ceil((a + b) / (float) a) - 1;
                else
                    c = ceil(rem / (float) a) - 1;
            }
        }

        m[i] = c;
    }

    sort(m.begin(), m.end());

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (k >= m[i]) { k -= m[i]; ret++; }
    }

    cout << ret << endl;
}
