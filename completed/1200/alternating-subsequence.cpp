//Category: 1200
//Link: https://codeforces.com/problemset/problem/1343/C
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> segs;

        int curMax;
        cin >> curMax;
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            if ((x > 0) != (curMax > 0)) {
                segs.push_back(curMax);
                curMax = x;
            }
            curMax = max(curMax, x);
        }
        segs.push_back(curMax);

        int sum = 0;
        for (int x : segs) sum += x;

        cout << sum << endl;
    }
}
