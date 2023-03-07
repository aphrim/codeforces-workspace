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

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int evenCount = 0, oddCount = 0;
        for (char c : s) {
            evenCount += (c - '0') % 2 == 0;
            oddCount += (c - '0') % 2 == 1;
        }
        if (oddCount < 2) {
            cout << -1 << endl;
            continue;
        }

        while ((s.back() - '0') % 2 == 0 ) {
            evenCount--;
            s.erase(s.size() - 1);
        }

        bool evenParity = (evenCount * 2 + oddCount) % 2 == 0;
        if (!evenParity) {
            for (int i = 0; i < n; i++) {
                if ((s[i] - '0') % 2 == 1) {
                    s.erase(i, 1);
                    break;
                }
            }
        }
        while (s[0] == '0') s.erase(0, 1);
        cout << s << endl;
    }
}
