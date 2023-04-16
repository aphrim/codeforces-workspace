<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long int

//#define USACO

=======
/*
ID: gregper1
TASK: 
LANG: C++
 */
#include <bits/stdc++.h>
#define int long long int

>>>>>>> b9422077be39d8bdc406410c70b1dfa99d286c0a
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

<<<<<<< HEAD
=======
int largeDiv(int a, int b) {
    return (a + b - 1) / b;
}

bool isPrime(int x) {
    if (x== 1) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

<<<<<<< HEAD:completed/cses/dice-combinations.cpp
int MOD = 1e9+7;

=======
>>>>>>> b9422077be39d8bdc406410c70b1dfa99d286c0a
>>>>>>> 21374ae4e69106be5a42863b7ee79144edd64a1d:contesttmp/a.cpp
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

<<<<<<< HEAD:completed/cses/dice-combinations.cpp
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= 6; j++) {
            if (i >= j) dp[i] += dp[i - j];
=======
<<<<<<< HEAD
#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

=======
    string pi = "314159265358979323846264338327";
>>>>>>> b9422077be39d8bdc406410c70b1dfa99d286c0a
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
<<<<<<< HEAD

        bool ret = true;
        int i = 0;
        if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') ret = false;
        for (i = 1; i < s.size(); i++) {
            if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') ret = false;
            if (s[i] == 'Y' && s[i-1] != 's') ret = false;
            if (s[i] == 'e' && s[i-1] != 'Y') ret = false;
            if (s[i] == 's' && s[i-1] != 'e') ret = false;
        }
        if (ret) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
=======
        int i = 0;
        for (; i < s.size(); i++) {
            if (s[i] != pi[i]) break;
>>>>>>> 21374ae4e69106be5a42863b7ee79144edd64a1d:contesttmp/a.cpp
        }
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;

    return 0;
}

>>>>>>> b9422077be39d8bdc406410c70b1dfa99d286c0a
