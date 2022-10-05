//Category: 1300
//Link: https://codeforces.com/problemset/problem/1555/B
//Complexity: O(1)
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int W, H;
        cin >> W >> H;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;

        if ((h + abs(y2 - y1) > H) && (w + abs(x2 - x1) > W)) {
            cout << -1 << endl;
            continue;
        }

        int dUp = 1e10, dLeft = 1e10;
        if (h + abs(y2 - y1) <= H)
            dUp = min(max(0ll, h - y1), max(0ll, y2 - (H - h)));
        if (w + abs(x2 - x1) <= W)
            dLeft = min(max(0ll, w - x1), max(0ll, x2 - (W - w)));
        cout << min(dUp, dLeft) << endl;
    }
}
