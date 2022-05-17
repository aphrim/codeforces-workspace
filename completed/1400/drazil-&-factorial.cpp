//Category: 1400
//Time complexity: O(nlog(n) + n)
//Link: https://codeforces.com/problemset/problem/515/C
//Had to look at tutorial for hint on how to do this.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int factorial(int x) {
    int ret = 1;
    while (x--) {
        ret *= x + 1; 
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> digits;
    while (n--) {
        char c;
        cin >> c;
        int cn = c - '0';
        int f;
        switch(cn) {
        case 0:
            f = -1;
            break;
        case 1:
            f = -1;
            break;
        case 2:
            f = 2;
            break;
        case 3:
            f = 3;
            break;
        case 4:
            f = 322;
            break;
        case 5:
            f = 5;
            break;
        case 6:
            f = 53;
            break;
        case 7:
            f = 7;
            break;
        case 8:
            f = 7222;
            break;
        case 9:
            f = 7332;
            break;
        }
        if (f != -1)
            while (f != 0) {
                digits.push_back(f % 10);
                f /= 10;
            }


    }

    sort(digits.begin(), digits.end(), [](int first, int second) {
        return first > second;
    });

    for (int n : digits) cout << n;
    cout << endl;
}
