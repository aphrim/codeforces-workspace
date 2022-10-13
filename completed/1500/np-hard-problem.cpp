//Category: 1500
//Link: https://codeforces.com/problemset/problem/687/A
//Complexity: O(nlogn)
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

unordered_map<int, vector<int>, custom_hash> edges;
set<int> s1, s2;
bool ret = true;

void dfs(int curVertex, bool b) {
    if (s1.count(curVertex) && !b)
        ret = false;
    if (s2.count(curVertex) && b)
        ret = false;
    if (s1.count(curVertex) || s2.count(curVertex)) return;

    if (b) s1.insert(curVertex);
    else s2.insert(curVertex);
    for (int v : edges[curVertex])
        dfs(v, !b);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (edges[i].size() > 0 && !s1.count(i) && !s2.count(i)) {
            dfs(i, true);
        }
    }

    if (!ret) {
        cout << -1 << endl;
        return 0;
    }

    cout << s1.size() << endl;
    for (int n : s1) {
        cout << n << " ";
    }
    cout << endl << s2.size() << endl;
    for (int n : s2) {
        cout << n << " " ;
    }
    cout << endl;


}
