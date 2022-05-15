//Category: 1400
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/520/B
//Another pretty easy 1400.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (m < n)
        cout << n - m << endl;
    else {
        int steps = 0;
        while (n != m) {
            if (m > n && m % 2 == 0)
                m /= 2;
            else
                m++;

            steps++;
        }
        cout << steps << endl;
    }

}
