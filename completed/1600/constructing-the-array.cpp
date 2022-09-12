//Category: 1600
//Link: https://codeforces.com/problemset/problem/1353/D
//Complexity: O(nlogn)
//Had to look at editorial for hint on how to represent indicies, learned that sets are always sorted and have custom comparators!
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct compare {
        bool operator() (const pair<int, int> lhs, const pair<int, int> rhs) const {
            int s1 = lhs.second - lhs.first;
            int s2 = rhs.second - rhs.first;
            if (s1 == s2) return lhs.first < rhs.first;
            else return s1 > s2;
        }
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        set<pair<int, int>, compare> ind;
        ind.insert({0, n-1});

        vector<int> ret(n, 0);

        for (int i = 0; i < n; i++) {   
            pair<int, int> cur = *ind.begin();
            int mid;
            if ((cur.second - cur.first + 1) % 2 == 0)
                mid = round((cur.first + cur.second - 1) / 2.0f);
            else mid = round((cur.first + cur.second) / 2.0f);
            ret[mid] = i + 1;
            ind.erase(cur);
            if (cur.first < mid) ind.insert({cur.first, mid - 1});
            if (cur.second > mid) ind.insert({mid + 1, cur.second});
        }

        cout << ret << endl;
    }
}
