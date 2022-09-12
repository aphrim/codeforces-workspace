//Category: 1300
//Link: https://codeforces.com/problemset/problem/1157/B
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<char> digits(n), remaps(10);

    for (int i = 0; i < n; i++) cin >> digits[i];
    
    for (int i = 1; i < 10; i++) cin >> remaps[i];

    bool b = false;
    for (int i = 0; i < n; i++) {
        if (remaps[digits[i] - '0'] >= digits[i]) {
            if (remaps[digits[i] - '0'] > digits[i])
                b = true;
            digits[i] = remaps[digits[i] - '0'];
        } else if (b) break;
    }

    for (char x : digits) cout << x;
    cout << endl;
}
