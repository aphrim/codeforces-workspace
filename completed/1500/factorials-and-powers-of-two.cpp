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

int popcount(int x) {
    int ret = 0;
    for (int i = 0; i < 64; i++)
        if (x & (1ll << i)) ret++;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> p2, facts;
    for (int i = 0; i <= 40; i++) p2.push_back(pow(2, i));
    int cur = 2;
    for (int i = 3; i < 15; i++) {
        cur *= i;
        facts.push_back(cur);
    }

    int t;
    cin >> t;
    while (t--) {
        int ret = INT_MAX;
        int n;
        cin >> n;
        for (int i = 0; i < pow(2, 15); i++) {
            int cur = n;
            int moves = 0;
            for (int j = 0; j < 13; j++) {
                if (i & (1 << j)) {
                    cur -= facts[j];
                    moves++;
                }
            }
            if (cur >= 0) {
                moves += popcount(cur);

                ret = min(ret, moves);
            }
        }
        cout << ret << endl;
    }

    return 0;
}

