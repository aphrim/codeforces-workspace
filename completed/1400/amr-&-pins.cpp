//Category: 1400
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/507/B
//Proud of being able to solve this one pretty quickly! Feel as though I am getting better at 1400s!
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, x, y, xn, yn;
    cin >> r >> x >> y >> xn >> yn;

    double manhattanDist = sqrt(abs(xn - x) * abs(xn - x) + abs(yn - y) * abs(yn - y));

    cout << ceil(manhattanDist / double(r*2)) << endl;
}
