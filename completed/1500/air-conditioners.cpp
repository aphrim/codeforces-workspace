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

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> vp(k);
        for (int i = 0; i < k; i++) cin >> vp[i].first;
        for (int i = 0; i < k; i++) cin >> vp[i].second;
        sort(vp.begin(), vp.end());
        vector<int> leftDP(n, INT_MAX), rightDP(n, INT_MAX);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) leftDP[i] = leftDP[i-1] + 1;
            if (j < k && vp[j].first - 1 == i) leftDP[i] = min(leftDP[i], vp[j].second), j++;
        }
        j = k - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) rightDP[i] = rightDP[i+1] + 1;
            if (j >= 0 && vp[j].first - 1 == i) rightDP[i] = min(rightDP[i], vp[j].second), j--;
        }
        for (int i = 0; i < n; i++) {
            cout << min(leftDP[i], rightDP[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}

