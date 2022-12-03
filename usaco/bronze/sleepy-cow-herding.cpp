#include <bits/stdc++.h>
#define int long long int

#define USACO

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

int calcMin(int x,int y,int z) {
    if (x == z - 2) return 0;
    if (y - x == 2 || z - y == 2)
        return 1;
    return 2;
}

int calcMax(int x, int y, int z) {
    return max(z - y - 1, y - x - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif

    int x, y, z;
    cin >> x >> y >> z;

    if (x > y) {
        int t = x;
        x = y;
        y = t;
    }
    if (x > z) {
        int t = x;
        x = z;
        z = t;
    }
    if (y > z) {
        int t = y;
        y = z;
        z = t;
    }

    cout << calcMin(x, y, z) << endl << calcMax(x, y, z) << endl;
}
