#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<string> words;
    for (int i = 0; i < count; i++) {
        string w;
        cin >> w;
        words.push_back(w);
    }
    for (string word : words) {
        if (word.size() <= 10)
            cout << word << endl;
        else {
            cout << word[0] << word.size() - 2 << word[word.size() - 1] << endl;
        }
    }

    return 0;
}
