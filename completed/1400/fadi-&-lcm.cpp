//Category: 1400
//Complexity: IDK, and don't want to think
//Link: https://codeforces.com/problemset/problem/1285/C
//Notes: I am tired
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int GCF(int a, int b) {
    int ret = 1;
    for (int i = 1; i <= sqrt(max(a, b)) + 1; i++) {
        if (a % i == 0 && b % i == 0) ret = i;
    }
    return ret;
}

int LCM(int a, int b) {
    if (a == b) return a;
    int gcf = GCF(a, b);
    return (a / gcf) * b;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int x;
    cin >> x;

    vector<int> divisors;

    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) { divisors.push_back(i); divisors.push_back(x / i); }
    }

    int m = pow(2, 63), a1, a2;
    for (int i = 0; i < divisors.size(); i++) {
        if (LCM(divisors[i], x / divisors[i]) == x) {
            if (max(divisors[i], x / divisors[i]) < m) {
                a1 = divisors[i];
                a2 = x / divisors[i];
            }
        }
    }
    cout << a1 << " " << a2 << endl;
}
