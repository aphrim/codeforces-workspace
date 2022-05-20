//Category: 1400
//Complexity: O(n) not including map hashing. 
//Link: https://codeforces.com/problemset/problem/1365/C
//Note: Find amount of cyclic shifts for number to match, find which shift count matches most numbers.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, int> locs; 
    map<int, int> diffs;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        locs[x] = i;
    }


    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int tLoc = locs[x];
        int dif;
        if (tLoc > i) dif = tLoc - i;
        else dif = n - i + tLoc;
        diffs[dif]++;
    }

    int ret = INT_MIN;
    for (auto it : diffs) {
        if (it.second > ret) ret = it.second;
    }

    cout << ret << endl;
}
