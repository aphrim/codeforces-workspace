#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int problems;
    cin >> problems;
    int ret = 0;
    for (int i = 0; i <= problems; i++) {
        string s;
        getline(cin, s);
        int co = 0;
        for (char c : s) {
            if (c == '1') co++;
        }
        if (co > 1) ret++;
    }
    cout << ret << endl;
    return 0;
}
