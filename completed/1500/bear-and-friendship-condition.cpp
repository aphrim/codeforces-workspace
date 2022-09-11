//Category: 1500
//Link: https://codeforces.com/problemset/problem/771/A
//Complexity: O(n)
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

unordered_map<int, bool, custom_hash> visited;
unordered_map<int, vector<int>, custom_hash> friendships; 
int vertCount = 0;
int edgeCount = 0;

void dfs(int node) {
    visited[node] = true;
    vertCount++;
    for (int con : friendships[node]) {
        edgeCount++;
        if (!visited[con]) {
            dfs(con);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friendships[a-1].push_back(b-1);
        friendships[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vertCount = 0, edgeCount = 0;
            dfs(i);
            if (edgeCount != vertCount * (vertCount - 1)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;


}
