//Category: 1400
//Link: https://codeforces.com/problemset/problem/437/C
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;


    vector<int> v(n);
    vector<pair<unordered_set<int>, int>> graph(n);
    vector<int> order(n);

    cin >> v;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        graph[s].first.insert(e);
        graph[s].second += v[e];
        graph[e].first.insert(s);
        graph[e].second += v[s];
    }

    for (int i = 0; i < n; i++) order[i] = i;

    int ret = 0;

    sort(order.begin(), order.end(), [&](int a, int b) {
        return v[a] > v[b];
    });

    for (int i = 0; i < order.size(); i++) {
        pair<unordered_set<int>, int> vertex = graph[order[i]];
        ret += vertex.second;
        for (int vertexI : vertex.first) {
            graph[vertexI].second -= v[order[i]];
            graph[vertexI].first.erase(order[i]);
        }
    }

    cout << ret << endl;
}
