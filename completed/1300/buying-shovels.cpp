//Category: 1300
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1360/D
#include <bits/stdc++.h>
#define int long long int

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int mC = INT_MAX;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i <= k)
                    mC = min(mC, n / i);
                if (n / i <= k)
                    mC = min(mC, i);
            }
        }
        cout << mC << endl;
    }
}
