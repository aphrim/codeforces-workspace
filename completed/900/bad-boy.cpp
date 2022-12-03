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

int n, m;

int dis(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

pair<int, int> furthestCorner(pair<int, int> cords) {
    int c1 = dis({1, 1}, cords), c2 = dis({n, 1}, cords), c3 = dis({1, m}, cords), c4 = dis({n, m}, cords);    
    int ma = max(c1, max(c2, max(c3, c4)));
    if (c1 == ma) return {1, 1};
    else if (c2 == ma) return {n, 1};
    else if (c3 == ma) return {1, m};
    else return {n, m};
}

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
        int i, j;
        cin >> n >> m >> i >> j;
        i--, j--;
        
        pair<int, int> p1 = furthestCorner({i, j});
        pair<int, int> p2 = furthestCorner(p1);

        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    }
}
