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
        int n;
        cin >> n;

        vector<vector<int>> grid;

        int nn = n;
        while (n--) {
            grid.push_back(vector<int>());
            for (int i = 0; i < nn; i++) {
                char x;
                cin >> x;
                grid.back().push_back(x - '0');
            }
        }


        bool ret = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1) {
                    if ((i < nn - 1 && grid[i + 1][j] != 1) && (j < nn - 1 && grid[i][j + 1] != 1)) {
                        ret = false;
                        break;
                    }
                }
            }
        }

        if (ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
