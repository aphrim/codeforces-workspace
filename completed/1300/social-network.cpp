//Category: 1300
//Link: https://codeforces.com/problemset/problem/1234/B2
//Complexity: O(n) not including hashing for set
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> screen;
    set<int> onScreen;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (onScreen.count(x) == 0) {
            screen.push_back(x);
            if (screen.size() > k)
                onScreen.erase(screen[screen.size() - k - 1]);
            onScreen.insert(x);
        }
    }

    int nConv = k < screen.size() ? k : screen.size();

    cout << nConv << endl;

    for (int i = 1; i <= nConv; i++) {
        cout << screen[screen.size() - i] << " "; 
    }
    cout << endl;



}
