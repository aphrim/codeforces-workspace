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

int binomial(int n, int k, int p) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		if (i <= k) dp[i][i] = 1;
    }

	for (int i = 0; i <= n; i++) for (int j = 1; j <= min(i, k); j++) if (i != j) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
	return dp[n][k];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //(n)(n-1)(n-2)(n-3)(n-4) * nchoose5 * 120
    //nchoose 5 * nchoose5 * 120


    int n;
    cin >> n;
    int MOD = 9.22e18;
    int bin = binomial(n, 5, MOD);
    cout << bin * bin * 120 << endl;
    
    

    return 0;
}

