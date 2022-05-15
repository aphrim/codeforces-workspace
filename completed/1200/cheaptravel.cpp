#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if ((float) b / (float) m > a) {
        cout << n * a << endl;
    } else {
        cout << min((n / m) * b + (n % m) * a, (int) ceil((float) n / (float)m) * b) << endl;
    }
    
}
