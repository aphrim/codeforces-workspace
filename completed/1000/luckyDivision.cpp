#include <bits/stdc++.h>

using namespace std;

bool isLucky(int n) {
    bool ret = true;
    while (n >= 1) {
        int dig = n % 10;
        ret = ret && (dig == 7 || dig == 4);
        n /= 10;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    if (isLucky(n))
        cout << "YES";
    else  {
        for (int i = 4; i < n; i++) {
            if (n % i == 0 && isLucky(i)) {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    
}
