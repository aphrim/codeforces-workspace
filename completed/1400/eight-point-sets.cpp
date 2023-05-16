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

    map<int, vector<int>> mappings;
    set<int> yVals;
    for (int i = 0; i < 8; i++) {
        int x, y;
        cin >> x >> y;
        mappings[x].push_back(y);
        yVals.insert(y);
    }

    vector<vector<int>> p;
    vector<int> ys;
    for (pair<int, vector<int>> pivi : mappings) p.push_back(pivi.second);
    for (int y : yVals) ys.push_back(y);

    if (p.size() != 3) {
        cout << "ugly" << endl;
        return 0;
    }

    if (p[0].size() != 3 || p[1].size() != 2 || p[2].size() != 3) {
        cout << "ugly" << endl;
        return 0;
    }

    sort(p[0].begin(), p[0].end());
    sort(p[1].begin(), p[1].end());
    sort(p[2].begin(), p[2].end());
    if (p[0][0] != ys[0] || p[0][1] != ys[1] || p[0][2] != ys[2]
    ||  p[2][0] != ys[0] || p[2][1] != ys[1] || p[2][2] != ys[2]
    ||  p[1][0] != ys[0] || p[1][1] != ys[2]) {
        cout << "ugly" << endl;
        return 0;
    }

    cout << "respectable" << endl;

    return 0;
}

