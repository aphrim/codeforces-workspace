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

set<int> intersection(set<int> s1, set<int> s2) {
    set<int> ret;
    for (int x : s1)
        if (s2.count(x))
            ret.insert(x);
    return ret;
}

set<int> factors(int x) {
    set<int> ret;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            ret.insert(i);
            ret.insert(x / i);
        }
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        set<int> commonDivisors;
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;

        int i = 1;
        while (i < n && a[i] == a[i - 1]) i++;
        if (i < n)
            commonDivisors = factors(abs(a[i] - a[i - 1]));
        for (; i < n; i++) {
            if (a[i] != a[i-1]) { 
                commonDivisors = intersection(commonDivisors, factors(abs(a[i] - a[i-1])));
            }
        }

        if (commonDivisors.count(0)) cout << -1 << endl;
        else {
            int ret = 0;
            for (int x : commonDivisors) ret = max(ret, x);
            if (ret == 0)
                cout << -1 << endl;
            else
                cout << ret << endl;
        }
    }
}

