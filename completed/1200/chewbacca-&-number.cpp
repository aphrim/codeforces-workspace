#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i++) {
        if ('9' - n[i] + '0' < n[i]) {
            if (i == 0 && '9' - n[i] + '0' == '0')
                continue;
            n[i] = '9' - n[i] + '0'; 
        }
    }

    cout << n << endl;
}
