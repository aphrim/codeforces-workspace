#include <bits/stdc++.h>
#define int long long int

//#define USACO

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename K, typename V> ostream& operator<<(ostream& out, map<K, V>& a) {for(pair<K, V> p : a) out << p.first << " " << p.second << '\n'; return out;};

//Credit: https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int l, r, x;
        cin >> l >> r >> x;
        int a, b;
        cin >> a >> b;

        if (abs(b - a) >= x) {
            cout << 1 << endl;
            continue;
        }

        if (b == a) {
            cout << 0 << endl;
            continue;
        }
        
        if (abs(r - b) < x && abs(l - b) < x) {
            cout << -1 << endl;
            continue;
        }
        if (b < l || b > r || a < l || b > r) {
            cout << -1 << endl;
            continue;
        }

        int mr = INT_MAX, ml = INT_MAX;
        if (abs(r - b) >= x) {
            if (r - a >= x) mr = 1;
            else if (a - l >= x) mr = 2;
            else mr = INT_MAX - 1;
            if (r - b >= x) mr++;
            else mr = INT_MAX;
        }
        if (abs(l - b) >= x) {
            if (a - l >= x) ml = 1;
            else if (r - a >= x) ml = 2;
            else ml = INT_MAX - 1;
            if (b - l >= x) ml++;
            else ml = INT_MAX;
        }
        if (min(ml, mr) > 5) {
            cout << -1 << endl;
        } else
            cout << min(ml, mr) << endl;

    }
}
