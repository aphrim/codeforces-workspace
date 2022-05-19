//Category: 1300
//Time Complexity: Worst case O(n)
//Link: https://codeforces.com/problemset/problem/25/A
//This was pretty easy for a 1300, 900 or 1000 would have been more suitable.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, b;
    cin >> c;
    b = c;
    int eC;
    vector<int> nums;
    while(c-->0) {
        int n;
        cin >> n;
        if (n % 2 == 0) eC++;
        nums.push_back(n);
    }

    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2 == 0) == (b - eC > eC)) {
            cout << i + 1 << endl;
            return 0;
        } 
    }
    
}
