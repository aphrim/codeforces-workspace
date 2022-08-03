//Category: 1400
//Link: https://codeforces.com/problemset/problem/1374/D
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> rCounts;
        int maxC = 0;
        int maxI = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % k == 0) continue;
            rCounts[k - x % k]++;;
            if (rCounts[k - x % k] > maxC || ((k - x % k > maxI) && rCounts[k - x % k] == maxC)) {
                maxC = rCounts[k - x % k];
                maxI = k - x % k;
            }
        }
        
        if (maxC == 0) {
            cout << 0 << endl; 
            continue;
        }

        int ret = (k * (maxC - 1)) + maxI + 1;
        cout << ret << endl;
    }
}
