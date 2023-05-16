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

vector<vector<int>> board;

set<pair<int, int>> visited;

bool t(int x) {
    return ((1 << 3) & x);
}
bool b(int x) {
    return ((1 << 1) & x);
}
bool r(int x) {
    return ((1 << 2) & x);
}
bool l(int x) {
    return ((1 << 0) & x);
}
void dfs(int x, int y) {
    if (visited.count({x, y})) return;
    visited.insert({x, y});
    if (!t(board[x][y])) dfs(x - 1, y);
    if (!b(board[x][y])) dfs(x + 1, y);
    if (!l(board[x][y])) dfs(x, y - 1);
    if (!r(board[x][y])) dfs(x, y + 1);

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    board = vector<vector<int>>(n, vector<int>(m));
    cin >> board;

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int pre = visited.size();
            dfs(i, j);
            if (visited.size() - pre > 0) ret.push_back(visited.size() - pre);
        }
    }
    sort(ret.begin(), ret.end(), [](int a, int b) { return a > b; });
    cout << ret << endl;

    return 0;
}

