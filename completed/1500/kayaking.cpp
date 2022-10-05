//Category: 1500
//Link: https://codeforces.com/contest/863/problem/B
//Complexity: O(n^3)
//O(nlogn) is possible, but don't feel like coding it.
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
 
    int n;
    cin >> n;
    vector<int> a(n * 2);
    cin >> a;
 
    sort(a.begin(), a.end());
 
    int ret = INT_MAX;
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n * 2; j++) {
            if (i == j) continue;
            int last = -1;
            int cur = 0;
            for (int k = 0; k < n * 2; k++) {
                if (k == i || k == j) continue;
                if (last == -1) 
                    last = a[k];
                else {
                    cur += a[k] - last;
                    last = -1;
                }
            }
            ret = min(ret, cur);
        }
    }
 
    cout << ret << endl;
 
}
