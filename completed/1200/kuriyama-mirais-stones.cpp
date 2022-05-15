#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums, prefixSum{0}, sortedPrefixSum{0};


    while(n--) {
        int x;
        cin >> x;
        nums.push_back(x);
        prefixSum.push_back(prefixSum.back() + x);
    }

    sort(nums.begin(), nums.end());

    for (int x : nums) {
        sortedPrefixSum.push_back(sortedPrefixSum.back() + x);
    }

    int questionCount;
    cin >> questionCount;

    while(questionCount--) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) {
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
        } else {
            cout << sortedPrefixSum[r] - sortedPrefixSum[l - 1] << endl;
        }
    }

    
}
