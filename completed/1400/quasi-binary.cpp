//Category: 1400
//Complexity: O(log10(n) * maxDigit(n))
//Link: https://codeforces.com/problemset/problem/538/B
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums;

    while (n > 0) {
        int x = n, y = 0, ymult = 1;
        while (x >= 1) {
            int r = x % 10;
            if (r != 0) {
                y += ymult;
            }
            ymult *= 10;
            x /= 10;
        }
        n -= y;
        nums.push_back(y);
    }

    cout << nums.size() << endl;
    for (int n : nums) cout << n << " ";
    cout << endl;
}
