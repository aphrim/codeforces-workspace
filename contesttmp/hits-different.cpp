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

vector<vector<int>> rows(2023, vector<int>(2023));
vector<pair<int, int>> place(1e6 + 1);
vector<int> dp(1e6 + 1, -1);

set<int> enc;
int dfs(int x) {
    if (enc.count(x)) return 0;
    if (dp[x] != -1) return dp[x];
    enc.insert(x);
    int ret = x * x;
    if (x == 1) return ret;
    int curRow = place[x].first, curInd = place[x].second;
    if (curInd > 0) ret += dfs(rows[curRow - 1][curInd - 1]);
    if (curInd < curRow) ret += dfs(rows[curRow - 1][curInd]);
    dp[x] = ret;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int curRow = 1, rowInd = 0;
    for (int i = 1; i <= 1e6; i++) {
        rows[curRow][rowInd] = i;
        place[i] = {curRow, rowInd};
        rowInd++;
        if (rowInd == curRow) rowInd = 0, curRow++;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        enc = set<int>();
        int ret = dfs(n);
        cout << ret << endl;
    }

    return 0;
}

