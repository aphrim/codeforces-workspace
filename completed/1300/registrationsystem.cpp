//Category: 1300
//Complexity: O(n) not including hashing on the users map.
//Link: https://codeforces.com/problemset/problem/4/C
//Very easy 1300, this is suitable for 800 or 900 IMO.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> users;
    while (n-->0) {
        string name;
        cin >> name;
        if (users[name] > 0)
            cout << name << users[name] << endl;
        else
            cout << "OK" << endl;
        users[name]++;
    }
    
    
}
