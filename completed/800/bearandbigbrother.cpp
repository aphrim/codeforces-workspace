#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ret = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ret++;
    }
    cout << ret << endl;
    
}

