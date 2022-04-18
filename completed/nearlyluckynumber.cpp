#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;


    int luckyDigits = 0;
    while (n >= 1) {
        int dig = n % 10;
        if (dig == 4 || dig == 7)
            luckyDigits++;

        n /= 10;
    }

    if (luckyDigits == 4 || luckyDigits == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
}
