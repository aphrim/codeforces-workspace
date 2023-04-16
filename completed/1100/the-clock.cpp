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
        char a, b, _, c, d;
        cin >> a >> b >> _ >> c >> d;
        a -= '0', b -= '0', c -= '0', d -= '0';
        int h = a * 10 + b, m = c * 10 + d;
        int orh = h, orm = m;
        int add;
        cin >> add;

        set<int> foundTimes;

        while (true) {
            m += add;
            while (m >= 60) m -= 60, h++;
            h %= 24;
            if ((m % 10 == h / 10) && (h % 10 == m / 10)) foundTimes.insert(h);
            if (h == orh && m == orm) break;
        }
        cout << foundTimes.size() << endl;

        
    }
}
