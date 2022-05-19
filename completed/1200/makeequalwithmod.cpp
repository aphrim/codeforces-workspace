#include <bits/stdc++.h>

using namespace std;

int main() {
    int tCount;
    cin >> tCount;
    while (tCount-->0) {
        int l;
        cin >> l;
        
        vector<int> nums;
        while (l-->0) {
            int n;
            cin >> n;
            nums.push_back(n);
        }

        sort(nums.begin(), nums.end());

        bool pres1 = false;
        bool cons = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) pres1 = true;
            if (i > 0 && nums[i-1] == nums[i] - 1) cons = true;
        }

        if (not pres1) cout << "YES" << endl;
        if (pres1 and not cons) cout << "YES" << endl;
        if (pres1 and cons) cout << "NO" << endl;
            
    }
    
}
