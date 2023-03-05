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

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;
    cin >> n;
    vector<char> in(n);
    cin >> in;

    // P == 0, H = 1, S = 2
    vector<vector<int>> prefix(3, vector<int>(n + 1)), suffix(3, vector<int>(n + 2));
    for (int i = 1; i <= n; i++) {
        prefix[0][i] = prefix[0][i - 1] + (in[i - 1] ==  'P');
        prefix[1][i] = prefix[1][i - 1] + (in[i - 1] ==  'H');
        prefix[2][i] = prefix[2][i - 1] + (in[i - 1] ==  'S');
    }
    for (int i = n; i >= 1; i--) {
        suffix[0][i] = suffix[0][i + 1] + (in[i - 1] ==  'P');
        suffix[1][i] = suffix[1][i + 1] + (in[i - 1] ==  'H');
        suffix[2][i] = suffix[2][i + 1] + (in[i - 1] ==  'S');
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, (
            max(prefix[0][i], max(prefix[1][i], prefix[2][i])) +
            max(suffix[0][i], max(suffix[1][i], suffix[2][i])))
        );
    }
    if (ret > n) ret = n;

    cout << ret << endl;

    return 0;
}

