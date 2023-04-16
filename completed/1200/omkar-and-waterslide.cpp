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
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;

        vector<pair<int, int>> ds;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i-1]) {
                r = i;
            } else {
                if (r > l) {
                    ds.push_back({l, r});
                }
                l = i;
            }
        }

        if (r > l) {
            ds.push_back({l, r});
        }

        int ret = 0;
        int mm = *max_element(a.begin(), a.end()), maxI = 0;
        for (pair<int, int> p : ds) {
            l = p.first, r = p.second;
            for (int i = r; i > l; i--) {
                ret += (a[i-1] - a[i]); 
            }
            if (a[l] == mm) maxI = r;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == mm && i > maxI) maxI = i;
        }

        cout << ret << endl;
    }
}
