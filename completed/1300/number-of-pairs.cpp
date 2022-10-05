//Category: 1300
//Link: https://codeforces.com/problemset/problem/1538/C
//Complexity: O(nlogn)
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
        int n, l, r, ret = 0;
        cin >> n >> l >> r;
        vector<int> a(n);
        cin >> a;

        sort(a.begin(), a.end());

        int j = 1, k = n - 1;

        for (int i = 0; i < a.size() - 1; i++) {
            int x = a[i];

            for (j=min(j, n - 1);j >= i + 1; j--)
                if (x + a[j] < l) break; 
            for (j=max(j,i+1); j < a.size(); j++)
                if (x + a[j] >= l) break;
            for (k=max(k,i+1); k > i; k--)
                if (x + a[k] <= r) break;

            if (j < a.size() && k > i && x + a[j] >= l && x + a[k] <= r)
                ret += k - j + 1;
        }


        cout << ret << endl;
    }
}
