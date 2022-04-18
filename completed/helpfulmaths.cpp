#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string eq;
    cin >> eq;
    vector<char> ops;
    for (int i = 0; i < eq.size(); i += 2) {
        ops.push_back(eq[i]);
    }
    sort(ops.begin(), ops.end());
    string ret;
    for (int i = 0; i < ops.size() - 1; i++) {
        ret += ops[i];
        ret += '+';
    }
    ret += ops[ops.size() - 1];
    cout << ret;
}
