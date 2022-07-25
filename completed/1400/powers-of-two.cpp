//Category: 1400
//Link: https://codeforces.com/problemset/problem/1095/C
//Complexity: Wierd, depends on too many factors.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> baseRep;

    for (int i = 0; i < 32; i++) {
        if ((n & (1 << i)))
            baseRep.push_back(n & (1 << i));
    }
    reverse(baseRep.begin(), baseRep.end());

    if (k < baseRep.size() || k > n) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    int i = 0;
    while (k > baseRep.size()) {
        while (baseRep[i] == 1) i++;
        baseRep[i] /= 2;
        baseRep.push_back(baseRep[i]);
    }

    for (int x : baseRep)
        cout << x << " ";
    cout << endl;
}
