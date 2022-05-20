//Complexity: 1400
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1195/C
//Almost got it figured out except for some edge cases myself, but had to look at solution for pointers.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    vector<pair<int, bool>> dp(n + 1);

    for (int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    pair<int, int> p = {0, 0};

    for (int i = 0; i < n; i++) {
        p = {max(p.first, p.second + a[i]), max(p.second, p.first + a[i + n])};
    }

    cout << max(p.first, p.second) << endl;
}
