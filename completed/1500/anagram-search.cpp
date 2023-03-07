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

    string s, c;
    cin >> s >> c;

    if (c.size() > s.size()) {
        cout << 0 << endl;
        return 0;
    }

    map<char, int> counts, target;
    for (int i = 0; i < c.size(); i++) counts[s[i]]++;
    for (char ch : c) target[ch]++;
    int i = 0;
    int j = c.size() - 1;
    int ret = 0;
    while (j < s.size()) {
        int qCount = counts['?'];
        bool flag = true;
        for (pair<char, int> p : target) {
            char ch = p.first;
            if (counts[ch] > target[ch]) flag = false;
            else qCount -= target[ch] - counts[ch];
        }
        if (qCount < 0) flag = false;
        ret += flag;
        counts[s[i]]--;
        i++, j++;
        if (j == s.size()) break;
        counts[s[j]]++;
    }
    cout << ret << endl;
}
