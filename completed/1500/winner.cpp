//Category: 1500
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/2/A
//Pretty easy and simple 1500, just a basic implementation problem.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<string, int> counts;
    set<string> winners;
    int m = INT_MIN;

    vector<pair<string, int>> input(n);

    for (int i = 0; i < n; i++) cin >> input[i].first >> input[i].second;

    for (int i = 0; i < n; i++) {
        counts[input[i].first] += input[i].second;
    }

    for (auto it : counts) m = max(m, it.second);

    for (auto it : counts) {
        if (it.second == m) winners.insert(it.first);
    }


    string ret;

    counts = map<string, int>();

    for (int i = 0; i < n; i++) {
        counts[input[i].first] += input[i].second;
        if (winners.count(input[i].first) == 1 && counts[input[i].first] >= m) { ret = input[i].first; break; }
    }



    cout << ret << endl;
}
