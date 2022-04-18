#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> nums;
    cin >> n;

    while(n-->0) {
        int x;
        cin >> x;
        nums.push_back(x);
    }


    int j = 0, k = 0;
    bool b = false;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            if (!b) j = i - 1;
            b = true;
            k = i;
        } else {
            if (b) {
                reverse(nums.begin() + j, nums.begin() + i);
                b = false;
                break;
            }
        }
    }
    if (b) {
        reverse(nums.begin() + j, nums.end());
        k = nums.size() - 1;
    }

    b = true;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) b = false;
    }

    if (b) {
        cout << "yes" << endl;
        cout << j + 1 << " " << k + 1 << endl;
    } else {
        cout << "no" << endl;

    }


}
