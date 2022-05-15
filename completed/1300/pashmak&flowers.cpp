//Category: 1300
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/459/B
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> a;

    cin >> n;
    while(n-->0) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int mi = *min_element(a.begin(), a.end());
    int ma = *max_element(a.begin(), a.end());

    int miC = 0;
    int maC = 0;

    for (int n : a) {
        if (n == mi) miC++;
        if (n == ma) maC++;
    }

    if (mi == ma)
        cout << 0 << " " << miC * (miC - 1) / 2 << endl;
    else
        cout << ma - mi << " " << miC * maC << endl;
}
