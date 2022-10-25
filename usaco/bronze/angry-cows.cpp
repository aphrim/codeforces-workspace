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
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    sort(a.begin(), a.end());

    int ret = 0;
    for (int i = 0; i < a.size(); i++) {
        int t = 1;
        int l = i, r = i;
        bool lB = false, rB = false;
        while (true) {
            int oldL = l, oldR = r;
            if (!rB) {
                for (int j = r; j < a.size(); j++) {
                    if (abs(a[j] - a[oldR]) > t) break;
                    else r = j;
                }
            }
            if (!lB) {
                for (int j = l; j >= 0; j--) {
                    if (abs(a[j] - a[oldL]) > t) break;
                    else l = j;
                }
            }
            if (l == oldL && r == oldR) break;
            if (l == oldL) lB = true;
            if (r == oldR) rB = true;
            else t++;
        }

        ret = max(ret, r - l + 1);
    }
    cout << ret << endl;
}
