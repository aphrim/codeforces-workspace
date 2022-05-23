//Category: 1400
//Link: https://codeforces.com/problemset/problem/1374/D
//Complexity: Algo is O(n), hashing into map is logarthmic.
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
        int n, k, x = 0;
        map<int, int> cnt;
        cin >> n >> k;

        while(n--) {
            int i;
            cin >> i;
            if (i % k != 0)
                cnt[k - i % k]++;
        }

        int maxCount = 1, r = 0;

        for (auto it : cnt) {
            if (it.second > maxCount) {
                maxCount = it.second;
                r = it.first;
            } if (it.second == maxCount && it.first > r) r = it.first;
        }

        cout << (maxCount - 1) * k + r + 1 << endl;
    }
}
