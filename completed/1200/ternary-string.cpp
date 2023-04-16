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
        bool flag = false;
        int mi = INT_MAX;
        string s;
        cin >> s;

        int count1 = 0, count2 = 0, count3 = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            count1 += s[i] == '1';
            count2 += s[i] == '2';
            count3 += s[i] == '3';
            while (true) {
                if (s[j] == '1' && count1 > 1) j++, count1--;
                else if (s[j] == '2' && count2 > 1) j++, count2--;
                else if (s[j] == '3' && count3 > 1) j++, count3--;
                else break;
            }
            if (count1 >= 1 && count2 >= 1 && count3 >= 1) {
                mi = min(i - j, mi);
                flag = true;
            }
        }
        if (flag)
            cout << mi + 1 << endl;
        else
            cout << 0 << endl;
    }
}
