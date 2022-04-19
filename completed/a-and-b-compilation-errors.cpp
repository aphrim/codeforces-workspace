#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int nn = n;

    map<int, int> nums;
    map<int, int> nums1;
    int first, second;

    while(nn-->0) {
        int x;
        cin >> x;
        nums[x]++;
    }

    nn = --n;

    while(nn-->0) {
        int x;
        cin >> x;
        nums[x]--;
        nums1[x]++;
    }

    for (auto it : nums) {
        if (it.second > 0) 
            first = it.first;
    }

    nn = --n;

    while(nn-->0) {
        int x;
        cin >> x;
        nums1[x]--;
    }

    for (auto it : nums1) {
        if (it.second > 0) 
            second = it.first;
    }

    cout << first << endl << second << endl;
}
