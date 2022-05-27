//Category: 1500
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1201/B
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int mElement = *max_element(nums.begin(), nums.end());

    int sum = 0;

    for (int n : nums) {
        sum += n;
    }

    if (sum % 2 == 0 && sum >= 2 * mElement)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
