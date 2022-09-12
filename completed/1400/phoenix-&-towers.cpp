//Category: 1400
//Complexity: O(n + nlogn(from sorting))
//Link: https://codeforces.com/problemset/problem/1515/C
//Note: Have fun
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
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, int>>t1 (n);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) { cin >> t1[i].first; t1[i].second = i; };
        sort(t1.begin(), t1.end(), [](pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; });
        vector<int> t2(m);
        for (int i = 0; i < n; i++) {
            t2[i - (int32_t(i / m) * m)] += t1[i].first;    
            ret[t1[i].second] = (i - (i / m * m) + 1);
        }
        if (*max_element(t2.begin(), t2.end()) - *min_element(t2.begin(), t2.end()) > x)
            cout << "NO \n"; 
        else
        {
            cout << "YES" << endl;
            for (int n : ret) cout << n << " ";
            cout << endl;
        }

    }
}
