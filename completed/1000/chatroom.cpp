#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0, j = 0;
    string t = "hello";
    for (;i < s.size(); i++) {
        if (s[i] == t[j]) {
            if (j > t.size() - 1)
                break;
            j++;
        }
    }

    if (j > t.size() - 1)
        cout << "YES";
    else
        cout << "NO";
    
}
