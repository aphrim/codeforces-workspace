//Category: 1300
//Link: https://codeforces.com/problemset/problem/508/B
//Complexity: O(n)
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

inline bool iseven(char c) {
    return c == '0' || c == '2' || c == '4' || c == '6' || c == '8';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;
    
    vector<int> evens;

    for (int i = 0; i < n.size(); i++) {
        if (iseven(n[i]))
            evens.push_back(i);
    }

    if (evens.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    int best = -1;
    bool g = false;
    for (int i = evens.size() - 1; i >= 0; i--) {
        if (n[evens[i]] < n.back()) {
            best = i;
            g = true;
        } else if (n[evens[i]] == n.back() && (g == false || best == -1)) { 
            best = i;
        }
    }

    if (best == -1) {
        int tmp = n[evens.back()];
        n[evens.back()] = n.back();
        n[n.size() - 1] = tmp;
    } else {
        int tmp = n[evens[best]];
        n[evens[best]] = n.back();
        n[n.size() - 1] = tmp;
    }

    cout << n << endl;
}
