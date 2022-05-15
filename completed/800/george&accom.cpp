#include <bits/stdc++.h>

using namespace std;

int main() {
    int rmC;
    cin >> rmC;
    int ret = 0;
    while (rmC-->0) {
        int p, q;
        cin >> p >> q;
        if (q - p > 1) ret++;
    }
    cout << ret;

    
}
