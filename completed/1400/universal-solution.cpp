//Category: 1400
//Link: https://codeforces.com/problemset/problem/1380/B
//Note: Pretty easy 1400, just finding the most occuring character.
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
        int countsR = 0, countsP = 0, countsS = 0;
        for (char c : s) {
            switch(c) {
                case 'R':
                    countsR++;
                    break;
                case 'P':
                    countsP++;
                    break;
                case 'S':
                    countsS++;
                    break;
            }
        }

        string ret;
        if (countsR >= countsP && countsR >= countsS) ret = string(s.size(), 'P');
        else if (countsP >= countsR && countsP >= countsS) ret = string(s.size(), 'S');
        else ret = string(s.size(), 'R');
        cout << ret << endl;
    }
}
