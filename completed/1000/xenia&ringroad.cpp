#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    long long int ret = 0;
    int pos = 1;
    cin >> n >> m;
    while (m-->0) {
        int a;
        cin >> a;
        if (a < pos)
            ret += (n - pos) + a;
        else
            ret += a - pos;
        pos = a;
    }
    cout << ret << endl;
}
