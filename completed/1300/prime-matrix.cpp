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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    vector<int> primes;
    for (int i = 2; i <= 1e6; i++) {
        if (isPrime(i)) primes.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            a[i][j] = *lower_bound(primes.begin(), primes.end(), x) - x;
        }
    }

    int ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            cur += a[i][j];
        }
        ret = min(ret, cur);
    }

    for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i][j];
        }
        ret = min(ret, cur);
    }

    cout << ret << endl;

    return 0;
}

