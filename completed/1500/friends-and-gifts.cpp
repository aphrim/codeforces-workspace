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

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    vector<int> fill;
    set<int> unused;
    for (int i = 1; i <= n; i++) unused.insert(i);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) fill.push_back(i);
        else unused.erase(a[i]);
    }
    int i = 0;
    vector<int> swp;
    for (int x : unused) {
        if (x == fill[i] + 1) swp.push_back(fill[i]);
        a[fill[i]] = x;
        i++;
    }

    for (int i = 1;  i < swp.size(); i += 2) {
        int tmp = a[swp[i]];
        a[swp[i]] = a[swp[i-1]];
        a[swp[i-1]] = tmp;
    }

    if (swp.size() % 2 == 1) {
        int j = swp[swp.size() - 1];
        for (int k = 0; k < fill.size(); k++) {
            int i = fill[k];
            if (i != j && a[i] != j + 1 && a[j] != i + 1) {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }

    cout << a << endl;




    return 0;
}

