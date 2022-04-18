#include <bits/stdc++.h>

using namespace std;

map<char, bool> vowels {
    {'a', true},
    {'e', true},
    {'i', true},
    {'o', true},
    {'u', true},
    {'y', true},
};

int main() {
    string s;
    cin >> s;

    string ret;
    for (char c : s) {
        if (vowels[tolower(c)] == true) continue;
        ret += '.';
        ret += tolower(c);

    }

    cout << ret << endl;
}
