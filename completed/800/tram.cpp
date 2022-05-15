#include <bits/stdc++.h>

using namespace std;

int main() {
    int stops, count = 0, m = 0;
    cin >> stops;
    while (stops-->0) {
         int a, b;
         cin >> a >> b;
         count -= a;
         count += b;
         m = max(count, m);
    }

    cout << m << endl;

    return 0;
}
