//Category: 1400
//Complexity: O(sqrt(n))
//Link: https://codeforces.com/problemset/problem/762/A
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    int i = 1, ret = -1;
    vector<int> lDivs;
    for (int x = 1; x <= sqrt(n); x++) { 
        if (n % x != 0) continue;
        if (i == k) ret = x;
        if (x != sqrt(n))
            lDivs.push_back(n / x);
        i++;
    }
    reverse(lDivs.begin(), lDivs.end());
    if (ret < 0 && k - i < lDivs.size()) ret = lDivs[k - i];
    cout << ret << endl;
}
