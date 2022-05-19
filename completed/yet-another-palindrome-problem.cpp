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
        vector<int> nums;

        while (n--) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        bool ret = false;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 2; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    cout << "YES" << endl;
                    ret = true;
                    break;
                }
            }
            if (ret) break;
        }

        if (!ret)
            cout << "NO" << endl;
    }
}
