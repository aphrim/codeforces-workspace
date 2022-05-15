#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-->0) {
        int n;
        cin >> n;
        if (n < 1400)
            cout << "Division 4" << endl;
        else if (n < 1600)
            cout << "Division 3" << endl;
        else if (n < 1900)
            cout << "Division 2" << endl;
        else
            cout << "Division 1" << endl;
    }
}
