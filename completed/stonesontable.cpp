#include <bits/stdc++.h>

using namespace std;

int main() {
    int sC;
    string stones;
    cin >> sC;
    cin >> stones;

    char l;
    int ret = 0;
    for (char c : stones) {
        if (c == l) ret++;
        l = c;
    }

    cout << ret << endl;

    
}
