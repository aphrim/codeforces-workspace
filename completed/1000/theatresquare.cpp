#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m, a;
    cin >> n >> m >> a;

    long long int x = ceil(n / (double)a) * ceil(m / (double)a);
    cout << setprecision(17) << x << endl;

    return 0;
}
