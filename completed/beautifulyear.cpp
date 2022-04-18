#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    for(;;) {
        n++; 
        int c = n;
        int digits[10] = {};
        while (c >= 1) {
            int dig = c % 10;
            digits[dig]++;
            c /= 10; 
        }
        bool t = true;
        for (int i = 0; i < 10; i++) {
            if (digits[i] > 1) t = false;
        }
        if (t) {
            cout << n << endl;
            break;
        }
    }
}
