//Category: 1300
//Link: https://codeforces.com/problemset/problem/1420/C1
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, _;
        cin >> n >> _;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> b;
        int l = 0;
        bool inc = true;
        for (int x : a) {
            if (x < l && inc) {
                inc = false;
                b.push_back(l);
            } else if (x > l && !inc) {
                inc = true;
                b.push_back(l * -1);
            }
            l = x;
        }
        if (inc) 
            b.push_back(l);

        int ret = 0;
        for (int x : b) ret += x;
        cout << ret << endl;
    }
}
