#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string outcomes;
    cin >> n >> outcomes;

    int cA = 0, cD = 0;

    for (char c : outcomes) {
        if (c == 'A') cA++;
        else cD++;
    }

    if (cA == cD)
        cout << "Friendship";
    else if (cA > cD)
        cout << "Anton";
    else
        cout << "Danik";
    
}
