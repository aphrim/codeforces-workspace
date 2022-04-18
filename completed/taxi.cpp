#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, taxis = 0;
    cin >> c;
    map<int, int> counts;
    while (c-->0) {
        int g;
        cin >> g;
        counts[g]++;
    }

    taxis += counts[4];
    
    while (counts[3] > 0) {
        taxis++;
        counts[3]--;
        if (counts[1] > 0) counts[1]--;
    }

    while (counts[2] > 0) {
        taxis++;
        counts[2]--;
        if (counts[2] > 0) counts[2]--;
        else if (counts[1] > 0) { counts[1]--; if(counts[1]>0) counts[1]--; }
    }

    while (counts[1] > 0) {
        taxis++;
        for (int j = 0; j < 4; j++)
            if (counts[1] > 0) counts[1]--;
    }

    cout << taxis << endl;
}
