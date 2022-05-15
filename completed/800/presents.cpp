#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ex[102] = {};
    int i = 0;
    while (n-->0) {
        int p;
        cin >> p;
        ex[p] = i + 1;
        i++;  
    }

    for (int i = 0; i < 101; i++) {
        if (ex[i] != 0) {
            cout << ex[i] << " ";
        }
    }
    
}
