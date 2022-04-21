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
        vector<int> nums;
        while (n-->0) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        n = nums.size();
        sort(nums.begin(), nums.end());

        int ret = 0, i = 0;

        for(;;) {
            int c = nums[i], cur = 1;

            while (cur < c) {
                i++;
                if (i >= nums.size()) break;
                c = nums[i];
                cur++;
            }

            i++;
            if (cur == c) ret++;
            if (i >= nums.size()) break;
        }

        cout << ret << endl;
    }
}
