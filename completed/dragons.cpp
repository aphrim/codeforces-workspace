#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons;

    while (n-->0) {
        int d, b;
        cin >> d >> b;
        dragons.push_back(pair<int, int>{d, b});
    }

    sort(dragons.begin(), dragons.end(), [](auto first, auto second) {
        return first.first < second.first;
    });

    bool cB = true;
    for (pair<int, int> d : dragons) {
        if (s <= d.first) {
            cB = false;
            break;
        } else
            s += d.second;
    }
    if (cB)
        cout << "YES";
    else
        cout << "NO";
    
}
