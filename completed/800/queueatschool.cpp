#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    string order;
    cin >> n >> t >> order;

    int i = 0;
    while(t-->0) {
        for (int i = 0; i < order.size() - 1; i++) {
            if (order[i] == 'B' && order[i + 1] == 'G') {
                char t = order[i + 1];
                order[i + 1] = order[i];
                order[i] = t;
                i++;
            }
        }
    }

    cout << order << endl;
}
