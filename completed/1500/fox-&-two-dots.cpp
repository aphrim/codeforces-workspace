//Category: 1500
//Link: https://codeforces.com/problemset/problem/510/B
//Complexity: O((nm)^2) Although it should never be that high that is only in theoretical worst case
//Passes constraits easily with 31ms out of 2000ms used.
//Although constraits is n,m <= 50
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

vector<vector<int>> board;
vector<vector<bool>> visited;
int n, m;

bool dfs(int x, int y, int startX, int startY, int depth) {
    if ((x == startX) && (y == startY) && (depth > 2)) {
        //cout << x << " " << y << " " << startX << " " << startY << endl;
        return true;
    }
    if (visited[x][y]) return false;
    if (board[x][y] != board[startX][startY]) return false;
    visited[x][y] = true;
    
    bool ret = false;
    
    if (x > 0) ret = dfs(x - 1, y, startX, startY, depth + 1);
    if (x < n  - 1) ret = ret || dfs(x + 1, y, startX, startY, depth + 1);
    if (y > 0) ret = ret || dfs(x, y - 1, startX, startY, depth + 1);
    if (y < m - 1) ret = ret || dfs(x, y + 1, startX, startY, depth + 1);

    //if (ret)
        //cout << x << " " << y << " " << startX << " " << startY << endl;

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool b = false;
    cin >> n >> m;

    board = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited = vector<vector<bool>>(n, vector<bool>(m));
            b = b || dfs(i, j, i, j, 0);
            if (b) break;
        }
        if (b) break;
    }

    if (b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
