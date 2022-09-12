//Category: 1500
//Link: https://codeforces.com/problemset/problem/165/B
//Complexity O(log n)
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

int calc(int n, int k) {
    int ret = n;
    int kk = k;
    int x = n / k;
    while (x != 0) {
        ret += x;
        kk *= k; 
        x = n / kk;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int high = INT_MAX, low = 0;
    while (low != high) {
        int mid = ceil((high + low) / 2.0d);
        if (calc(mid, k) > n) high = mid - 1;
        else if (calc(mid, k) == n) {
            low = mid;
            break;
        }
        else low = mid;
    }

    if (calc(low, k) < n) low++;

    cout << low << endl;;
}
