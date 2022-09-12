//Category: 1300
//Link: https://codeforces.com/problemset/problem/1692/F
//Complexity O(n) for reading input, O(1) for the rest.
//Code isn't clean, but it is fast, at max does 1k loops (outside of reading data) even for datasets with millions of numbers.
//Pretty proud of this algorithim as well.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> digitCounts(10);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            digitCounts[x % 10]++;
        }
        bool b = false;
        for (int i = 0; i < 10; i++) {
            if (digitCounts[i]) {
                digitCounts[i]--;
                for (int j = 0; j < 10; j++) {
                    if (digitCounts[j]) {
                        digitCounts[j]--;
                        for (int k = 0; k < 10; k++) {
                            if (digitCounts[k] && ((i + j + k) % 10 == 3)) {
                                b = true;
                                break;
                            }
                        }
                        digitCounts[j]++;
                        if (b) break;
                    }
                }
                digitCounts[i]++;
                if (b) break;
            }
        }

        if (b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
