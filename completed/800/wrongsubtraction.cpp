#include <bits/stdc++.h>

using namespace std;

int main() {
    long int n, ops;
    cin >> n >> ops;
    while(ops-->0) {
        if (n % 10 == 0) n/= 10;
        else n--;
    }
    cout << n << endl;
}
