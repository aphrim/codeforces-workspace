#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<char> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<char> patches(n, '.');

        int pg = INT_MAX, ph = INT_MAX;
        int count = 0;
        for (int i = 0; i < n; i++) {
            char c = v[i];
            if (c == 'H' && abs(ph - i) > k) {
                ph = i + k; 
                if (ph >= n) {
                    if (patches[n-1] != '.') patches[n - 2] = 'H';
                    else patches[n-1] = 'H';
                } else patches[ph] = 'H';
                count++;
            } else if (c == 'G' && abs(pg - i) > k) {
                pg = i + k; 
                if (pg >= n) {
                    if (patches[n-1] != '.') patches[n - 2] = 'G';
                    else patches[n-1] = 'G';
                } else patches[pg] = 'G';
                count++;
            }
        }

        cout << count << endl;
        for (char c : patches) cout << c;
        cout << endl;
    }
}
