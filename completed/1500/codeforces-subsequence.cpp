//Category: 1500
//Link: https://codeforces.com/problemset/problem/1368/B
//Complexity: Wierd, but runs at good speed.
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

int prod(vector<int> v) {
    int ret = 1;
    for (int n : v) ret *= n;
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(10, 1);

    int n;
    cin >> n;

    int i = 0;
    while (prod(v) < n) {
        v[i % 10]++;
        i++;
    }

    string s = "codeforces";

    for (int k = 0; k < 10; k++) {
        for (int c = 0; c < v[k]; c++)
            cout << s[k];
    }
    cout << endl;
}
