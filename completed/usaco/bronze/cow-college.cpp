#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end(), [](int a, int b) {
        return b < a;
    });;

    int maxSum = 0, maxT = 0;
    for (int i = 0; i < n; i++) {
        if (((i + 1) * c[i]) >= maxSum) {
            maxSum = (i + 1) * c[i];
            maxT = c[i];
        }
    }

    cout << maxSum << " " << maxT << endl;

}
