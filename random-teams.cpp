#include <bits/stdc++.h>
#define int long long int

using namespace std;

int prngs(int n) {
    if (n == 1) return 0;
    n--;
    return n * (n + 1) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ma = prngs(n - m + 1);
    int mi;


    mi = prngs(n / m) * m + n % m; 

    cout << mi << " " << ma << endl;
}
