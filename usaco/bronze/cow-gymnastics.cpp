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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
#endif

    int k, n;
    cin >> k >> n;
    
    set<pair<int, int>> pairs;

    vector<int> a(n);
    cin >> a;
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            pairs.insert({a[j], a[k]});
        }
    }

    for (int i = 0; i < k - 1; i++) {
        set<pair<int, int>> curPairs;
        cin >> a;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (pairs.count({a[j], a[k]}))
                    curPairs.insert({a[j], a[k]});
            }
        }

        pairs = curPairs;
    }

    cout << pairs.size() << endl;
}
