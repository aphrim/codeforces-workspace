#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    vector<int> books;
    cin >> n >> t;
    
    while(n-->0) {
        int x;
        cin >> x;
        books.push_back(x);
    }


    int i = 0, j = 0, runningSum = books[0], m = -1;

    while (j < books.size()) {
        if (runningSum <= t) {
            m = max(m, j - i);
            if (j < books.size() - 1) {
                j++;
                runningSum += books[j];
            } else break;
        } else {
            runningSum -= books[i];
            i++;
        }
    }
    cout << m + 1 << endl;
}
