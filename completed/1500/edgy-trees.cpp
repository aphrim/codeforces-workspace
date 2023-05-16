/*
ID: gregper1
TASK: 
LANG: C++
 */
#include <bits/stdc++.h>
#define int long long int

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

int largeDiv(int a, int b) {
    return (a + b - 1) / b;
}

bool isPrime(int x) {
    if (x== 1) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

//Find all compoonents which are fully red, and subtract possible sequences within that component, dsu?

map<int, vector<pair<int, bool>>> edges;
vector<int> componentSizes;
set<int> enc;

int dfs(int cur) {
    if (enc.count(cur)) return 0;
    enc.insert(cur);
    int ret = 1;
    for (pair<int, bool> edge : edges[cur]) if (!edge.second) ret += dfs(edge.first);

    return ret;
}

int MOD = 1e9 + 7;

int pow(int a, int b) {
    int ret = 1;
    for (int i = 0; i < b; i++) ret *= a, ret %= MOD;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        edges[u].push_back({v, x});
        edges[v].push_back({u, x});
    }

    for (int i = 0; i < n; i++) {
        int size = dfs(i);
        if (size > 0)
            componentSizes.push_back(size);
    }

    int total = pow(n, k);
    for (int size : componentSizes) total -= pow(size, k);
    while (total < 0) total = MOD + total;
    total %= MOD;
    cout << total << endl;




    return 0;
}

