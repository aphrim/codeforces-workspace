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

vector<int> sizes(int m) {
    int pSize = 0, rSize = 1, total = 0;;
    vector<int> ret;
    while (total <= m) {
        pSize += rSize;
        total += pSize;
        ret.push_back(total);
        rSize++;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("balls.in", "r", stdin);
    freopen("balls.out", "w", stdout);
#endif

    int t;
    cin >> t;
    vector<int> a(t);
    cin >> a;
    int m = *max_element(a.begin(), a.end());
    vector<int> pS = sizes(m + 1);
    vector<int> dp(m + 1);
    for (int i = 0; i <= m; i++) dp[i] = i;
    for (int i = 1; i <= m; i++) {
        for (int size : pS) {
            if (size <= i) {
                dp[i] = min(dp[i], dp[i - size] + 1);
            }
        }
    }
    for (int x : a)
        cout << dp[x] << endl;
}
