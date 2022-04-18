#include <bits/stdc++.h>

using namespace std;

int main() {
    int cord;
    cin >> cord;

    int minSteps = cord / 5;
    if (cord % 5 > 0) minSteps++;
    cout << minSteps << endl;
    return 0;
}
