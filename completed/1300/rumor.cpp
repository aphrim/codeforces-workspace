//Category: 1300
//Link: https://codeforces.com/problemset/problem/893/C
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

set<int> visited;
map<int, vector<int>> cons;
vector<int> costs;
int mi = INT_MAX;

void dfs(int cur) {
    if (visited.count(cur)) return;
    mi = min(mi, costs[cur]);
    visited.insert(cur);

    for (int con : cons[cur]) {
        dfs(con);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    costs = vector<int>(n);
    cin >> costs;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cons[a].push_back(b);
        cons[b].push_back(a);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            dfs(i);
            ret += mi;
            mi = INT_MAX;
        }
    }

    cout << ret << endl;
}

