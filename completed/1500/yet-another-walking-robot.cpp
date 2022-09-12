//Category: 1500
//Link: https://codeforces.com/problemset/problem/1296/C
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        map<pair<int, int>, int> lPs;
        pair<int, int> cur{0,0};
        lPs[cur] = 1;
        int i = 2, l = -1, r = INT_MAX;
        for (char c : s) {
            if (c == 'L') cur.first++;
            if (c == 'R') cur.first--;
            if (c == 'U') cur.second++;
            if (c == 'D') cur.second--;
            if (lPs[cur] != 0 && (i - lPs[cur] < r - l)) {
                l = lPs[cur];
                r = i;
            }
            lPs[cur] = i;
            i++;
        }

        if (l == -1) {
            cout << -1 << endl;
        } else {
            cout << l << " " << r - 1 << endl;
        }
    }
}
