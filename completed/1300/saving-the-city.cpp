//Category: 1300
//Link: https://codeforces.com/problemset/problem/1443/B
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
        string s; 
        int cost = 0, a, b;
        cin >> a >> b >> s;
        
        int i = 0;
        while (s[i] == '0' && i < s.size()) i++;
        if (s[i] == '1') cost += a;

        while (i < s.size()) {
            while (s[i] == '1' && i < s.size()) i++;
            int nmc = 0;
            while (s[i] == '0' && i < s.size()) {
                i++;
                nmc++;        
            }
            if (i < s.size() && s[i] == '1')
                cost += min(a, b * nmc);
        }

        cout << cost << endl;
    }
}
