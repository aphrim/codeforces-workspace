//Category: 1300
//Complexity: I don't know. Best geuss is O(n*m)
//Link: https://codeforces.com/problemset/problem/1348/B
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-->0) {
        int n, k;
        cin >> n >> k;

        set<int> distinctNums;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            distinctNums.insert(a);
        }

        if (distinctNums.size() > k) cout << -1 << endl;
        else {
            cout << n * k << endl;
            while(n-->0) {
                for (int x : distinctNums) cout << x << " ";
                for (int i = 0; i < k - distinctNums.size(); i++) cout << 1 << ' ';
            }
            cout << endl;
        }
    }
}
