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
        int n, h, m;
        cin >> n >> h >> m;
        vector<pair<int, int>> alarms(n);
        for (int i = 0; i < n; i++) {
            cin >> alarms[i].first >> alarms[i].second;
        }

        int minH = 24, minM = 60;
        for (pair<int, int> alarm : alarms) {
            if (alarm.first == h && alarm.second == m) {
                minH = 0;
                minM = 0;
                break;
            }

            int curh, curm;
            if (alarm.first < h) curh = (24 - h) + alarm.first;
            else curh = alarm.first - h;
            if (alarm.second < m) {
                curh--;
                curm = (60 - m) + alarm.second;
                if (curh == -1) curh = 23;
            } else curm = alarm.second - m;

            if ((curh < minH) || (curh == minH && curm < minM)) {
                minH = curh;
                minM = curm;
            }
        }

         cout << minH << " " << minM << endl;
    }
}
