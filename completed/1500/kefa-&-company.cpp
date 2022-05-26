//Category: 1500
//Complexity: O(nlogn + n) (nlogn for sorting, n for iterating the 2 pointers in sliding window manner)
//Link: https://codeforces.com/problemset/problem/580/B
//Note: Sort, then find greatest total with sliding window.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> ms(n);

    for (int i = 0; i < n; i++) cin >> ms[i].first >> ms[i].second;

    sort(ms.begin(), ms.end(), [](pair<int, int> first, pair<int, int> second) {
        return first.first < second.first;
    });

    int ret = ms[0].second, cur = ms[0].second;
    
    int i = 0, j = 0;

    while (j >= i) {
        j++;
        if (j >= ms.size()) break;
        cur += ms[j].second;

        while (ms[j].first - ms[i].first >= d) {
            cur -= ms[i].second;
            i++;
        }

        ret = max(ret, cur);
    }

    cout << ret << endl;
}
