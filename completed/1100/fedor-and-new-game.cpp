#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> counts;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    int f;
    cin >> f;
    bitset<32> fb (f);

    int ret = 0;

    for (auto it : counts) {
        bitset<32> nb (it.first);
        int dif = 0;
        for (int i = 0; i < 32; i++) {
            if (nb[i] != fb[i]) dif++;
        }

        if (dif <= k) ret += it.second;
    }

    cout << ret << endl;
}
