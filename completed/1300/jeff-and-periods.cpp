//Category: 1300
//Link: https://codeforces.com/problemset/problem/352/B
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<int, vector<int>> numbers;
    vector<pair<int, int>> ret;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers[x].push_back(i);
    }

    for (pair<int, vector<int>> p : numbers) {
        if (p.second.size() == 1) {
            ret.push_back({p.first, 0});
        } else {
            int prog = p.second[1] - p.second[0];
            bool isProg = true;
            for (int i = 1; i < p.second.size(); i++) {
                if (p.second[i] - p.second[i-1] != prog) {
                    isProg = false;
                    break;
                }
            }
            if (isProg) ret.push_back({p.first, prog});
        }
    }

    sort(ret.begin(), ret.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    });

    cout << ret.size() << endl;
    for (pair<int, int> x : ret) cout << x.first << " " << x.second << endl;
}
