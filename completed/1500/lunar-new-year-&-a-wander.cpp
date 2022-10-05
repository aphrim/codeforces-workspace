//Category: 1500
//Link: https://codeforces.com/problemset/problem/1106/D
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> possible;
    set<int> used;
    unordered_map<int, vector<int>, custom_hash> edges;
    vector<int> ret{1};

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    used.insert(1);
    for (int edge : edges[1]) {
        if (edge != 1)
            possible.insert(edge);
    }

    while(possible.size() > 0) {
        int cur = *possible.begin();
        possible.erase(cur);
        used.insert(cur);
        ret.push_back(cur);
        for (int edge : edges[cur]) {
            if (!used.count(edge)) possible.insert(edge);
        }
    }

    cout << ret << endl;
}
