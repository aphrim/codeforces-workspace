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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    int countNegs = 0, maxNeg = -INT_MAX, minPos = INT_MAX, maxNegI, minPosI, negI = -1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x < 0) {
            countNegs++;
            maxNeg = max(x, maxNeg);
            if (x == maxNeg) maxNegI = i;
        } else if (x == 0){
            negI = i;
        } else {
            minPos = min(minPos, x);
            if (x == minPos) minPosI = i;
        }
    }

    bool flipPos = false, flipNeg = false, subZ = false;
    if (countNegs % 2 == 1) {
        if (negI > 0)
            subZ = true;
        else if (minPosI < abs(maxNegI))
            flipPos = true;
        else flipNeg = true;
    }

    int moves = 0;
    for (int i = 0; i < n; i++) {
        if (flipPos && i == minPosI) moves += a[i] + 1;
        else if (flipNeg && i == maxNegI) moves += a[i] * -1 + 1;
        else if (a[i] == 0 && subZ) moves++;
        else if (a[i] == 0) moves++;
        else moves += abs(a[i]) - 1;
    }
    cout << moves << endl;
}
