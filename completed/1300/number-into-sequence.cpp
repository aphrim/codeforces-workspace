//Category: 1300
//Link: https://codeforces.com/problemset/problem/1454/D
//Complexity: I don't know but probably pretty bad. Completes all test cases with 109 ms though.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

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

vector<int> factor(int n) {
    vector<int> ret{1};
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && ((n / i) % i == 0)) ret.push_back(i); 
    }
    return ret;
}

vector<int> recFactor(int n, int last) {
    vector<int> factors = factor(n); 
    vector<int> ret{n};
    for (int f: factors) {
        if (f != 1 && f % last == 0) {
            vector<int> r = recFactor(n / f, f);
            if (r.size() + 1 > ret.size()) {
                reverse(r.begin(), r.end());
                r.push_back(f);
                reverse(r.begin(), r.end());
                ret = r;
            }
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
        int n;
        cin >> n;

        vector<int> ret = recFactor(n, 1);
        cout << ret.size() << endl;
        for (int x  : ret) cout << x << " ";
        cout << endl;
    }
}
