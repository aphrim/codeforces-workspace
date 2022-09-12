#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ret = 0;
        if (s[1] == s[0]) {
            ret++;
            s[1] = '-';
        }
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
                ret++;
                s[i] = '-';
            }
        }

        cout << ret << endl;

    }
}
