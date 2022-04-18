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

    while(n-->0) {
        string x;
        cin >> x;
        counts[x]++;
    }

    int m = INT_MIN;
    string w;

    for (auto it : counts) {
        if (it.second > m) {
            w = it.first;
            m = it.second;
        }
    }

    cout << w << endl;
}
