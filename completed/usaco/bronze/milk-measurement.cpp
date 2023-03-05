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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, pair<string, int>>> log(n);
    for (int i = 0; i < n; i++) {
        cin >> log[i].first >> log[i].second.first; 
        char sign;
        cin >> sign;
        cin >> log[i].second.second;
        if (sign == '-') log[i].second.second *= -1;
    }

    sort(log.begin(), log.end(), [](auto a, auto b) {return a.first < b.first;});

    int milk0 = 7, milk1 = 7, milk2 = 7;
    int lastBest = 7, ret = 0;
    for (auto  p : log) {
        if (p.second.first == "Bessie")
            milk0 += p.second.second;
        else if (p.second.first == "Elsie")
            milk1 += p.second.second;
        else
            milk2 += p.second.second;

        int best = 0;
        if (milk0 >= milk1 && milk0 >= milk2)
            best += 1;
        if (milk1 >= milk0 && milk1 >= milk2)
            best += 2;
        if (milk2 >= milk0 && milk2 >= milk1)
            best += 4;

        ret += best != lastBest;
        lastBest = best;
    }

    cout << ret << endl;
}
