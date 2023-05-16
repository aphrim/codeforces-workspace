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

int MOD = 1e9 + 7;

int p(int x) {
    int ret = 1;
    for (int i = 2; i <= x; i++) {
        ret  *= 2;
        ret %= MOD;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> board(h, vector<int>(w, -1));
    bool flag = true;
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            if (board[i][j] == 0) flag = false;
            board[i][j] = 1;
        }
        if (x < w) {
            if (board[i][x] == 1) flag = false;
            board[i][x] = 0;
        }
    }
    for (int i = 0; i < w; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            if (board[j][i] == 0) flag = false;
            board[j][i] = 1;
        }
        if (x < h) {
            if (board[x][i] == 1) flag = false;
            board[x][i] = 0;
        }
    }


    if (!flag) {
        cout << 0 << endl;
        return 0;
    }

    int count = 1;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            count += (board[i][j] == -1);

    cout << p(count) << endl;

    return 0;
}

