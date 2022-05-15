#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;


    bool caps = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') caps = false;
    }

    if (caps && s.size() > 1) {
        for (int i = 1; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }

        if (s[0] >= 'a')
            s[0] = toupper(s[0]); 
        else
            s[0] = tolower(s[0]);
    }
    if (s.size() == 1 && s[0] > 'Z')
        s[0] = toupper(s[0]); 
    else if (s.size() == 1)
        s[0] = tolower(s[0]);


    cout << s << endl;
    
}

