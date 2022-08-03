#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, start = 0;
        cin >> n;
        vector<int> a(n);
        cin >> a;
        unordered_map<int, int> counts;
        int overCounts = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            counts[x]++;
            if (counts[x] > 1) overCounts++;
        }
        for (int i = 0; i < overCounts;) {
            if (counts[a[start]] > 1) overCounts--;
            counts[a[start]]--;
            start++;
        }

        cout << start << endl;
    }
}
