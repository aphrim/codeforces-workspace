//Category: 1500
//Link: https://codeforces.com/problemset/problem/1366/C
//Complexity: complicated
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

//Credit: https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<vector<int>> matr;
int m, n;

vector<int> getDiagonal(int i) {
    vector<int> ret;
    if (i < m) {
        int curx = i, cury = 0;
        while (curx >= 0 && cury < n) {
            ret.push_back(matr[cury][curx]);
            curx--;
            cury++;
        }
    } else {
        int curx = m - 1, cury = i - m + 1;
        while (curx >= 0 && cury < n) {
            ret.push_back(matr[cury][curx]);
            curx--;
            cury++;
        }
    }
    return ret;
}



int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        matr = vector<vector<int>>(n, vector<int>(m));
        cin >> matr;

        int count = 0;
        int max = (m + n - 1) / 2;
        for (int i = 0; i < max; i++) {
            vector<int> l = getDiagonal(i), r = getDiagonal(m + n - 2 - i);
            int countl0 = 0, countl1 = 0, countr0 = 0, countr1 = 0;

            for (int x : l) if (x == 0) countl0++; else countl1++;
            for (int x : r) if (x == 0) countr0++; else countr1++;

            count += min(countl0 + countr0, countl1 + countr1);
        }

        cout << count << endl;
    }
}
