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
        vector<int> nums;
        while (n-->0) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());

        vector<int> ret;

        int i = nums.size() / 2, j = nums.size() / 2 - 1;
        for (;j >= 0 && i < nums.size();) { 
            ret.push_back(nums[i]);
            ret.push_back(nums[j]);
            i++;
            j--;
        }

        if (nums.size() % 2 == 1)
            ret.push_back(nums.back());

        for (int n : ret) {
            cout << n << " ";
        }
        cout << endl;

    }
}
