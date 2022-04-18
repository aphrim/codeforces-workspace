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
