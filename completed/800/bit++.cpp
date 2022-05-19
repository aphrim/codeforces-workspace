#include <iostream>
#include <string>

using namespace std;

int main() {
    int count;
    cin >> count;

    int ret = 0;
    for (int i = 0; i <= count; i++) {
        string s;
        getline(cin, s);
        for (char c: s) {
            if (c == '+')
                ret++;
            else if (c == '-')
                ret--;
            else
                continue;
            break;
        }
    }
    cout << ret << endl;
}
