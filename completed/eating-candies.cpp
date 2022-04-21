#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t-->0) { 
        int n;
        cin >> n;
        vector<int> cs;

        while (n-->0) { 
            int x;
            cin >> x;
            cs.push_back(x);
        }

        int i = 0, j = cs.size() - 1;
        int w1 = cs[i], w2 = cs[j];
        int ret = 0, cur = 2;

        while (i < j) {
            if (w1 < w2) {
                cur++;
                i++;
                w1 += cs[i];
            } else if (w2 < w1) {
                cur++;
                j--;
                w2 += cs[j];
            } else if (w1 == w2) {
                ret = cur;
                i++, j--;
                w1 += cs[i];
                w2 += cs[j];
                cur += 2;
            }
        }

        cout << ret << endl;
    }
}
