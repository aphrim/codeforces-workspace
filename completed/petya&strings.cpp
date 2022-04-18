#include <iostream>
#include <string>

using namespace std;

void lower(string& s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (char) tolower(s[i]);
    }
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    lower(s1);
    lower(s2);
    if (s1 == s2) cout << "0";
    else {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) cout << "-1";
            else if (s1[i] > s2[i]) cout << "1";
            if (s1[i] != s2[i]) break;
        }
    }
    return 0;
}
