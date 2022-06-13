//Category: 1400
//Complexity: Chunky
//Link: https://codeforces.com/problemset/problem/1490/E
//Note: Easy problem to get a basic solution, optimizing to not get TLE took like 2 hours.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

bool cW(int i, vector<pair<int, int>> a) {
    int x = a[i].second;
    for (int j = 0; j < a.size(); j++) {
        if (i == j) continue;
        if (x >= a[j].second) x += a[j].second;
        else return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {   
        int n;
        cin >> n;
        vector<pair<int, int>>a(n);
        vector<int> s(n + 1), ret;

        for (int i = 0; i < n; i++) {
            a[i].first = i;
            cin >> a[i].second;
        }

        sort(a.begin(), a.end(), [](auto a, auto b) {
            return a.second < b.second;
        });

        int mi = -1, ma = a.size() - 1;
        while (ma > mi + 1) {
            int i = (mi + ma) / 2;
            if (cW(i, a)) ma = i;
            else mi = i;
        }
        for (int j = ma; j < a.size(); j++) ret.push_back(a[j].first);


        sort(ret.begin(), ret.end());
        cout << ret.size() << endl;
        for (int x : ret) {
            cout << x + 1 << " ";
        }
        cout << endl;


    }
}
