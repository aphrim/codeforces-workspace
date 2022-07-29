//Category: 1300
//Link: https://codeforces.com/problemset/problem/1077/C
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sum = 0;
    cin >> n;

    vector<int> a(n), sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sorted[i] = a[i];
    }

    sort(sorted.begin(), sorted.end());
    sum -= sorted.back();

    vector<int> ret;

    for (int i = 0; i < n; i++) {
        if (a[i] != sorted.back()) {
            if (sorted.back() == sum - a[i])
                ret.push_back(i);
        } else {
            if (sorted[sorted.size() - 2] == sum - sorted[sorted.size() - 2])
                ret.push_back(i);
        }
    }

    cout << ret.size() << endl;
    for (int x : ret) cout << x + 1 << " ";
    cout << endl;



}
