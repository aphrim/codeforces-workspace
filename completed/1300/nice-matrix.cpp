//Category: 1300
//Link: https://codeforces.com/problemset/problem/1422/B
//Complexity: O(n * m)
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int ret = 0;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<vector<int>> matrixNew(n, vector<int>(m));
        cin >> matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int n1 = matrix[i][j], n2 = matrix[n - i - 1][j],
                n3 = matrix[i][m - j - 1], n4 = matrix[n - i - 1][m - j - 1];

                vector<int> nums{n1, n2, n3, n4};
                sort(nums.begin(), nums.end());
                int avg = (nums[1] + nums[2]) / 2;

                matrixNew[i][j] = avg, matrixNew[n - i - 1][j] = avg, matrixNew[i][m - j - 1] = avg,
                matrixNew[n - i - 1][m - j - 1] = avg;
            }
        }

        cout << endl;
        //for (vector<int> row : matrixNew)
            //cout << row << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret += abs(matrixNew[i][j] - matrix[i][j]);
            }
        }
        cout << ret << endl;
    }
}
