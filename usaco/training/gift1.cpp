/*
ID: gregper1
TASK: gift1 
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

    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> names (n);
    map<string, int> m;
    map<string, int> initial;
    cin >> names;

    for (int i = 0; i < n; i++) {
        string gname;
        int money, g;
        cin >> gname >> money >> g;

        if (g == 0) continue;

        initial[gname] = money;
        m[gname] += money % g;
        for (int j = 0; j < g; j++) {
            string name;
            cin >> name;
            m[name] += money / g;
        }
    }

    for (string name : names) {
        cout << name << " " << m[name] - initial[name] << endl;
    }



    return 0;
}

