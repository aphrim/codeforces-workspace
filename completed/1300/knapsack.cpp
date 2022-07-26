//Category: 1300
//Link: https://codeforces.com/contest/1446/problem/A
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;

        vector<pair<int, int>> weights(n);

        for (int i = 0; i < n; i++) {
            int weight;
            cin >> weight;
            weights[i] = {weight, i};
        }

        sort(weights.begin(), weights.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        });

        int i = 0, j = 1, curSum = weights[0].first;
        while (j > i) {
            if (curSum > w) {
                curSum -= weights[i].first;
                i++;
            } else if (curSum < (w+1) / 2) {
                if (j == n) break;
                curSum += weights[j].first;
                j++;
            } else {
                break;
            }
        }

        if (curSum >= (w+1)/2 && curSum <= w && j - i > 0) {
            cout << j - i << endl;
            for (int k = i; k < j; k++) {
                cout << weights[k].second + 1 << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
