//Category: 1400
//Complexity: O(n)
//Link: https://codeforces.com/problemset/problem/698/A
//This was fun, had to think for a bit, but solution is pretty simple.
//After going over a day, set the days value to what was done that day
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> days;
    while(n-->0) {
        int x;
        cin >> x;
        days.push_back(x);
    }

    int ret = 0;
    for (int i = 0; i < days.size(); i++) {
        if (days[i] == 0) ret++; 
        if (days[i] == 1 || days[i] == 2) {     
            if (i > 0 && days[i-1] == days[i]) {
                days[i] = 0;
                ret++;
            }
        } else if (days[i] == 3) {
            if (i > 0) {
                if (days[i-1] == 1) days[i] = 2;
                else if (days[i-1] == 2) days[i] = 1;
            }
        }
    }

    cout << ret << endl;
}
