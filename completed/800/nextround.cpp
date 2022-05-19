#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    int count, target;
    int ret = 0;
    cin >> count;
    cin >> target;
    vector<int> scores;
    for (int i = 0; i < count; i++) {
        int n;
        cin >> n;
        scores.push_back(n);
    }
    for (int n : scores) {
        if (n >= scores[target - 1] && n > 0)
            ret++;
    }
    cout << ret << endl;
    return 0;
}
