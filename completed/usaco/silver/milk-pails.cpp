/*
ID: gregper1
TASK: 
LANG: C++
 */

//Not complete solution, only solves 7/9
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

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, k, m;
    cin >> x >> y >> k >> m;
    if (y > x) {
        int t = x;
        x = y;
        y = t;
    }

    vector<int> possible{0};
    if (k >= 1) possible.push_back(y), possible.push_back(x);
    if (k >= 2) possible.push_back(x + y);

    for (int i = 1; i < k; i++) {
        if (x > 0) possible.push_back(x);
        else break;
        x -= y;
    }

    for (int n = 1;; n++) {
        int moves = (n * 2 - 1);
        if (moves > k) break;
        if (y * n > x + y) break;
        possible.push_back(y * n);
    }

    int minDis = abs(m - possible[0]);
    for (int x : possible) minDis = min(abs(m - x), minDis);
    cout << minDis << endl;

    return 0;
}

