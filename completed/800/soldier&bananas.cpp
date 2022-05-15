#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int k, n, w;
    int i = 0;
    cin >> k >> n >> w;

    while (n > 0 && i < w) {
        i++;
        n -= k * i;
    }

    int b = -n;

    while (i < w) {
        i++;
        b += k * i;
    }
    cout << max(0, b) << endl;
    
    return 0;
}
