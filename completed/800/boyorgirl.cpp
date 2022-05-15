#include <iostream>
#include <string>

using namespace std;

int main() {
    char used[26] = {};
    int distinct = 0;
    string name;
    cin >> name;
    for (char c : name) {
        if (used[c - 'a'] == 0) distinct++;
        used[c - 'a']++;
    }
    cout << (distinct % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");

}
