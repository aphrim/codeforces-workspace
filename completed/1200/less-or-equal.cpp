#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums;
    while (n-->0) {
        int x;
        cin >> x;
        nums.push_back(x);
    }


    sort(nums.begin(), nums.end());

    if (k > 0 && (k == nums.size() || nums[k - 1] < nums[k])) {
        cout << nums[k-1] << endl;
    } else if (k > 0) {
        cout << -1 << endl;
    } else {
        if (k == 0 && nums[0] > 1)
            cout << nums[0] - 1 << endl;
        else if (k == 0 || nums[0] < 1 || (nums.size() > 1 && nums[1] == nums[0]))
            cout << -1 << endl;
        else cout << nums[0] << endl;
    }
}
