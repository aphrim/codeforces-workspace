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

        bool isEmpty = true;
        for (char c : s) if (c != '?') isEmpty = false;

        if (isEmpty) s[0] = 'B';

        if (s[0] == '?') {
            int dis;
            bool nextisB;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '?') {
                    dis = i;
                    nextisB = s[i] == 'B';
                    break;
                }
            }
            if ((nextisB && dis % 2 == 0) || (!nextisB && dis % 2 == 1)) s[0] = 'B';
            else s[0] = 'R';
        }
        
        for (int i = 1; i < n; i++) {
            if (s[i] == '?') {
                if (s[i-1] == 'R') s[i] = 'B';
                else s[i] = 'R';
            }
        }

        cout << s << endl;

    }
}
