#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, m = INT_MAX, ret;
    vector<int> fences;
    cin >> n >> k;

    while (n-->0) {
        int x;
        cin >> x;
        fences.push_back(x);
    }

    int i = 0, j = k - 1, cur = 0;

    for (int b = 0; b < j; b++) {
        cur += fences[b];
    }
    m = cur;
    ret = 1;

    while (j < fences.size() - 1) {
        cur -= fences[i];
        i++, j++;
        cur += fences[j];
        if (cur < m)
            ret = i + 1;
        m = min(m, cur);
    }

    cout << ret << endl;
}
