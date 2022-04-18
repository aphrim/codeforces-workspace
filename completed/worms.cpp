#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    vector<int> prefixSum{0};
    cin >> n;

    while (n-->0) {
        int x;
        cin >> x;
        prefixSum.push_back(prefixSum.back() + x);
    }

    cin >> m;

    while (m-->0) {
        int x;
        cin >> x;
        int l = 0, r = prefixSum.size() - 1, mid = 0;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (prefixSum[mid] < x)
                l = mid + 1;
            if (prefixSum[mid] >= x && (mid == 0 || prefixSum[mid - 1] < x))
                break;
            else if (prefixSum[mid] >= x)
                r = mid - 1;
        }

        cout << mid << endl;
    }

}
