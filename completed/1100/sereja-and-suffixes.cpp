#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> distinct{0};
    map<int, int> counts;
    vector<int> nums;

    while(n-->0) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    reverse(nums.begin(), nums.end());

    for (int n : nums) {
        if (counts[n] == 0)
            distinct.push_back(distinct.back() + 1);
        else
            distinct.push_back(distinct.back());
        counts[n]++;
    }

    reverse(distinct.begin(), distinct.end());
    
    while(m-->0) {  
        int x;
        cin >> x;
        cout << distinct[x-1] << endl;
    }
}
