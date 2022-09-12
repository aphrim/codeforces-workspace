//Category: 1300
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1037/C
//Pretty easy, just solved after being sad about not being able to solve any harder problems.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin >> _;

    string a, b;
    cin >> a >> b;

    int ret = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] != b[i]) {
            if ((a[i + 1] != b[i + 1]) && (a[i] != a[i + 1])) {
                a[i + 1] = b[i + 1];
                i++;
            }
            ret++;
        }
    }

    if (a.back() != b.back()) ret++;

    cout << ret << endl;
}
