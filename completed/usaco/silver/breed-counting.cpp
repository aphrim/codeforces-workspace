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

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> prefix1(n + 1);
    vector<int> prefix2(n + 1);
    vector<int> prefix3(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix1[i + 1] = prefix1[i] + (x == 1);
        prefix2[i + 1] = prefix2[i] + (x == 2);
        prefix3[i + 1] = prefix3[i] + (x == 3);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << prefix1[r] - prefix1[l-1] << " ";
        cout << prefix2[r] - prefix2[l-1] << " ";
        cout << prefix3[r] - prefix3[l-1] << endl;
    }

    return 0;
}

