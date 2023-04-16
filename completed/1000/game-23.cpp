#include <bits/stdc++.h>
#define int long long int

//#define USACO

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

map<int, int> factors(int x) {
    map<int, int> ret;
    while (x % 3 == 0) {
        x /= 3;
        ret[3]++;
    }
    while (x % 2 == 0) {
        x /= 2;
        ret[2]++;
    }
    if (x != 1) ret[x]++;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    if (m < n) cout << "-1" << endl;
    else {
        map<int, int> fn = factors(n), fm = factors(m);
        int diff2 = 0, diff3 = 0;
        bool flag = false;
        for (pair<int, int> p : fn) {
            if (!fm[p.first]) flag = true;
        }
        for (pair<int, int> p : fm) {
            if (p.first == 3) {
                diff3 = p.second - fn[3];
            } else if (p.first == 2) {
                diff2 = p.second - fn[2];
            } else {
                if (!fn[p.first]) flag = true;
            }
        }
        if (flag) cout << "-1" << endl;
        else if (diff2 < 0 || diff3 < 0) cout << "-1" << endl;
        else cout << diff2 + diff3 << endl;
    }
}
