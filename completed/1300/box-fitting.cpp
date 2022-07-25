//Category: 1300
//Link: https://codeforces.com/problemset/problem/1498/B
//Complexity: IDK
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
        int n, w;
        cin >> n >> w;
        
        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            counts[x]++;
        }

        int ret = 0, rectsLeft = n;
        while (rectsLeft) {
            int wl = w;  
            int hP = 20;
            while (wl ) {
                if (hP < 0) break;
                while (wl >= pow(2, hP) && counts[pow(2, hP)]) {
                    counts[pow(2, hP)]--;
                    wl -= pow(2, hP);
                    rectsLeft--;
                }
                hP--;
            }
            ret++;
        }
        cout << ret << endl;
        



    }
}
