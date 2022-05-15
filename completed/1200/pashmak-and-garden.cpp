#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int miX = min(x1, x2);
    int maX = max(x1, x2);
    int miY = min(y1, y2);
    int maY = max(y1, y2);

    auto eq = [&](int x, int y) -> bool { return (x == x1 && y == y1) || (x == x2 && y == y2); };

    int sX = maX - miX;
    int sY = maY - miY;

    if ((sY == 0 || sX == 0) || (sX == sY) && !(sX == 0 && sY == 0)) {
        sX = max(sX, sY);
        sY = sX;
        if (!eq(miX, miY))
            cout << miX << " " << miY << " ";
        if (!eq(miX + sX, miY))
            cout << miX + sX << " " << miY << " ";
        if (!eq(miX, miY + sY))
            cout << miX << " " << miY + sY << " ";
        if (!eq(miX + sX, miY + sY))
            cout << miX + sX << " " << miY + sY << " ";
        cout << endl;
    } else
        cout << -1 << endl;
}
