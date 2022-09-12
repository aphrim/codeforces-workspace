//Category: 1400
//Link: https://codeforces.com/problemset/problem/650/A
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
    int nn = n;

    unordered_map<int, int> xCoords;
    unordered_map<int, int> yCoords;
    unordered_map<int, int> coordCounts;

    while (n--) {
        int x, y;
        cin >> x >> y;
        xCoords[x]++;
        yCoords[y]++;
        coordCounts[x * nn + y]++;
    }

    int ret = 0;
    for (pair<int, int> p : xCoords) {
        ret += p.second * (p.second - 1) / 2;
    }
    for (pair<int, int> p : yCoords) {
        ret += p.second * (p.second - 1) / 2;
    }
    for (pair<int, int> p : coordCounts) {
        ret -= p.second * (p.second - 1) / 2;
    }

    cout << ret << endl;
}
