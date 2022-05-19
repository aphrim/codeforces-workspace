#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a1, a2;
    int ret = 0;
    cin >> a1 >> a2;

    while (min(a1, a2) > 0 && (!(a1 == 1 && a2 == 1))) {
        ret++;
        if (a1 < a2) {
            a1++;
            a2 -= 2;
        } else {
            a2++;
            a1 -= 2;
        }
    }

    cout << ret << endl;
}
