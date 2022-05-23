//Category: 1400
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/514/B
//Pretty easy, but edge cases were a bit annoying (Precision errors and infinite slopes)

#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    unordered_set<double> slopes;
    bool a = false;

    while(n--) {
        int x1, y1;
        cin >> x1 >> y1;

        if (x1 - x == 0)
            a = true;
        else
            slopes.insert(double(y1 - y) / double(x1 - x));
    }


    cout << slopes.size() + (a ? 1 : 0) << endl;
}
