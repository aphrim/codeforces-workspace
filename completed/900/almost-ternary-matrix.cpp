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

vector<vector<int>> matr;

int neighbors(int i, int j) {
    int v = matr[i][j];
    int ret = 0;
    if (j > 0 && matr[i][j-1] != v) ret++;
    if (j < matr[0].size() - 1 && matr[i][j+1] != v) ret++;
    if (i > 0 && matr[i-1][j] != v) ret++;
    return ret;
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
        int n, m;
        cin >> n >> m;
        matr = vector<vector<int>>(n, vector<int>(m, -1));
        for (int i = 0; i < m / 2; i++) {
            if (i % 2 == 0) {
                matr[0][i * 2] = 1;
                matr[0][i * 2 + 1] = 0;
            } else {
                matr[0][i * 2] = 0;
                matr[0][i * 2 + 1] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (neighbors(i-1, j) < 2)
                    matr[i][j] = !matr[i-1][j];
                else
                    matr[i][j] = matr[i-1][j];
            }
        }
        for (vector<int> v : matr)
            cout << v << endl;

    }
}
