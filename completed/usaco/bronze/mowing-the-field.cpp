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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;

    int x = 1001, y = 1001;
    vector<vector<int>> grid(2002, vector<int>(2002));

    int t = 0, minT = -1;

    for (pair<char, int> p : a) {
        switch(p.first) {
            case 'N':
                for (int i = 0; i < p.second; i++) {
                    y++;
                    if (grid[x][y]) {
                        if (minT == -1) minT = t - grid[x][y];
                        minT = min(minT, t - grid[x][y]);
                    }
                    grid[x][y] = t;
                    t++;
                }
                break;
            case 'S':
                for (int i = 0; i < p.second; i++) {
                    y--;
                    if (grid[x][y]) {
                        if (minT == -1) minT = t - grid[x][y];
                        minT = min(minT, t - grid[x][y]);
                    }
                    grid[x][y] = t;
                    t++;
                }
                break;
            case 'E':
                for (int i = 0; i < p.second; i++) {
                    x++;
                    if (grid[x][y]) {
                        if (minT == -1) minT = t - grid[x][y];
                        minT = min(minT, t - grid[x][y]);
                    }
                    grid[x][y] = t;
                    t++;
                }
                break;
            case 'W':
                for (int i = 0; i < p.second; i++) {
                    x--;
                    if (grid[x][y]) {
                        if (minT == -1) minT = t - grid[x][y];
                        minT = min(minT, t - grid[x][y]);
                    }
                    grid[x][y] = t;
                    t++;
                }
        }
    }

    cout << minT << endl;
}
