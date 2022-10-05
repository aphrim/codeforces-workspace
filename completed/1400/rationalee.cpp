//Category: 1400
//Link: https://codeforces.com/problemset/problem/1369/C
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), w(k);
        cin >> a >> w;

        sort(w.begin(), w.end());
        int lastOne = -1;
        for (int i = 0; i < w.size(); i++) 
            if (w[i] == 1) lastOne = i;
        reverse(w.begin() + lastOne + 1, w.end());
        sort(a.begin(), a.end());
        int l = 0, r = n - 1, sum = 0;
        for (int i = 0; i < k; i++) {
            int c = w[i];
            if (c == 1) sum += a[r--] * 2;
            else if (c == 2) {
                sum += a[r] + a[l];
                l++;
                r--;
            } else {
                sum += a[r];
                sum += a[l];
                r--;
                l += c - 1;
            }
                
        }

        cout << sum << endl;
    }
}