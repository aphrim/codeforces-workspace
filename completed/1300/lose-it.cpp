//Category: 1300
//Link: https://codeforces.com/problemset/problem/1176/C
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0;
    cin >> n;

    unordered_map<int, int> seq, counts;
    seq.insert({4, 0});
    seq.insert({8, 1});
    seq.insert({15, 2});
    seq.insert({16, 3});
    seq.insert({23, 4});
    seq.insert({42, 5});

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = seq[x];
        if (x == 0) counts[x]++;
        else {
            if (counts[x-1] == 0) ret++;
            else counts[x-1]--, counts[x]++;
        }
    }

    for (pair<int, int> p : counts) {
        if (p.first != 5) ret += p.second * (p.first + 1);
    }

    cout << ret << endl;

}
