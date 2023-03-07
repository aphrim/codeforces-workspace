/*
ID: gregper1
TASK: 
LANG: C++
 */
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

int largeDiv(int a, int b) {
    return (a + b - 1) / b;
}

bool isPrime(int x) {
    if (x== 1) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;
        int minIndex = min_element(a.begin(), a.end()) - a.begin();
        int minEl = a[minIndex];

        vector<vector<int>> ops;
        if (minIndex == 1) {
            ops.push_back({1, 2, minEl + 1, minEl});
        }
        for (int i = 1; i < n; i++) {
            if (i != minIndex) {
                vector<int> op(4);
                if (i < minIndex) op = {i + 1, minIndex + 1, a[i-1] + 1, minEl};
                else op = {minIndex + 1, i + 1, minEl, a[i-1] + 1};
                a[i] = a[i-1] + 1;
                if (i == minIndex - 1) {
                    int x = minEl;
                    while ((__gcd(x, a[i-1]) != 1) || (__gcd(x, minEl) != 1)) x++;
                    op[2] = x, a[i] = x;
                }
                ops.push_back(op);
            }
        }
        cout << ops.size() << endl;
        for (vector<int> op : ops) cout << op << endl;
    }

    return 0;
}

