#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int lCount;
    int sLength;
    vector<int> lampPositions;
    cin >> lCount;
    cin >> sLength;

    for (int i = 0; i < lCount; i++) {
        int p;
        cin >> p;
        lampPositions.push_back(p);
    }
    sort(lampPositions.begin(), lampPositions.end());

    int m = 0;
    
    for (int i = 1; i < lampPositions.size(); i++) {
        m = max(m, lampPositions[i] - lampPositions[i - 1]);
    }

    m = max(m, lampPositions[0] * 2);
    m = max(m, (sLength - lampPositions[lampPositions.size() - 1]) * 2);

    cout.precision(17);
    cout << m / 2.0d << endl;
}
