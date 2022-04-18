#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, pairs = 0;
    cin >> n;

    map<int, int> boys, girls;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        boys[x]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        girls[x]++;
    }

    for (auto it : boys) {
        int skill = it.first;
        int count = it.second;

        if (girls[skill - 1] > 0) {
            int gCount = girls[skill - 1];
            girls[skill - 1] -= min(count, gCount);
            pairs += min(count, gCount);
            count -= min(count, gCount);
        }

        if (girls[skill] > 0) {
            int gCount = girls[skill];
            girls[skill] -= min(count, gCount);
            pairs += min(count, gCount);
            count -= min(count, gCount);
        }

        if (girls[skill + 1] > 0) {
            int gCount = girls[skill + 1];
            girls[skill + 1] -= min(count, gCount);
            pairs += min(count, gCount);
            count -= min(count, gCount);
        }
    }

    cout << pairs << endl;
}
