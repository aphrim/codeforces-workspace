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

    //False if greater than 2(corner), 3(side), 4(center)
    //Otherwise increase
    

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m)), res(n, vector<int>(m));
        cin >> a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i][j] = 4;
        for (int i = 0; i < m; i++)
            res[0][i] = 3, res[n - 1][i] = 3;
        for (int i = 0; i < n; i++)
            res[i][0] = 3, res[i][m - 1] = 3;
        res[0][0] = 2, res[0][m-1] = 2, res[n-1][0] = 2, res[n-1][m-1] = 2;


        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > res[i][j]) flag = false;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            for (vector<int> v : res)
                cout << v << endl;
        } else cout << "NO\n";
    }
}
