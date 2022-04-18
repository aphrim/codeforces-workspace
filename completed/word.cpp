#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int uCount = 0;
    int lCount = 0;
    for (char c : s) 
        if (c < 'a')
            uCount++;
        else
            lCount++;
    for (int i = 0; i < s.size(); i++) {
        if (uCount > lCount) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }

    cout << s << endl;
    
}
