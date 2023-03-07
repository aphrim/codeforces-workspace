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

    int n;
    cin >> n;

    vector<int> maxV(2003, -INT_MAX), minV(2003, INT_MAX), maxH(2003, -INT_MAX), minH(2003, INT_MAX); 
    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        maxV[x + 1001] = max(maxV[x + 1001], y + 1001);
        minV[x + 1001] = min(minV[x + 1001], y + 1001);
        maxH[y + 1001] = max(maxH[y + 1001], x + 1001);
        minH[y + 1001] = min(minH[y + 1001], x + 1001);
        points.push_back({x + 1001, y + 1001});
    }

    int ret = 0;

    for (pair<int, int> p : points) {
        int x = p.first, y = p.second;
        if (minV[x] < y && maxV[x] > y && minH[y] < x && maxH[y] > x) ret++;
    }
    cout << ret << endl;


}
