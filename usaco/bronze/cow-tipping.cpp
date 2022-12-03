#include <bits/stdc++.h>
#define int long long int

#define USACO

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
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }


    int ret = 0;
    while (true) {
        bool flag = true;
        for (vector<int> v : a)
            for (int x : v)
                flag = flag && (x == 0);
        if (flag) break;

        ret++;

        int x, y;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (a[i][j] == 1)
                    x = i, y = j;

        for (int i = 0; i <= x; i++) 
            for (int j = 0; j <= y; j++)
                a[i][j] = !a[i][j];
    }

    cout << ret << endl;
}
