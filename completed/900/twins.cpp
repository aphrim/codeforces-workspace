#include <bits/stdc++.h>

using namespace std;

int main() {
    int CC;
    cin >> CC;

    vector<int> coins;
    while (CC-->0) {
        int n;
        cin >> n;
        coins.push_back(n);
    }

    int sum = 0;
    for (int n : coins) sum += n;
    float half = sum / 2.0f;

    sort(coins.begin(), coins.end(), [](int f, int s) { return f < s; });

    int running = 0;
    int c = 0;
    for (int i = coins.size() - 1; i >= 0; i--) {
        c++;
        running += coins[i];
        if (running > half) break;
    }
    cout << c << endl;

    
}
