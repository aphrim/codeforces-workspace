#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t-->0) {
        int n;
        cin >> n;
        map<int, int> counts;
        while(n-->0) {  
            int x;
            cin >> x;
            counts[x]++;
        }

        int mC = 0, mCN, unqC = 0;

        for (auto it : counts) {
            if (it.second > mC) {
                mC = it.second;
                mCN = it.first;
            }
            unqC++;
        }
        unqC--;

        if (mC - unqC >= 2)
            mC--, unqC++;

        cout << min(mC, unqC) << endl;
    }
}
