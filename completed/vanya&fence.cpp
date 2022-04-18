#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, w = 0;
    cin >> n >> h;

    while (n-->0) {
        int x;
        cin >> x;
        if (x > h)
            w += 2;
        else
            w++;
    }

    cout << w << endl;

    
}
