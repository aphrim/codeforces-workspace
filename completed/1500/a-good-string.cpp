//Category: 1500
//Link: https://codeforces.com/problemset/problem/1385/D
//Complexity: O(log(n))
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

string s;

int rec(int l, int r, char cur) {
    if (l == r) return s[l] != cur;  
    if (l == r - 1) {
        int cl = s[l] != cur + 1;
        int cr = s[r] != cur + 1;
        int fl = s[l] != cur;
        int fr = s[r] != cur;
        return min(cl + fr, cr + fl);
    }
    
    int mid = (l + r) / 2;
    int cl = rec(l, mid, cur + 1);
    int cr = rec(mid + 1, r, cur + 1);
    int fl = 0, fr = 0;

    for (int i = l; i <= r; i++) {
        if (i <= mid) fl += s[i] != cur;
        else fr += s[i] != cur;
    }

    return min(cl + fr, cr + fl);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> s;

        int l = 0, r = n - 1;
        cout << rec(l, r, 'a') << endl;
    }
}
