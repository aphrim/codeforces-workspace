#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c = 0, ret = 0;;
    cin >> a >> b;

    for (;;) {
        a--;
        c++;
        ret++;
        if (c == b) {
            c -= b;
            a++;
        }
        if (a == 0)
            break;
    }

    cout << ret << endl;
    
}
