//Category: 1500
//Link: https://codeforces.com/problemset/problem/977/E
//Complexity: Idk
//Accepted on first try!
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename U, typename V> istream& operator>>(istream& in, pair<U, V>& a) {in >> a.first >> a.second; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    cin >> edges;

    set<int> exVerts;
    map<int, vector<int>> cons;
    int ret = 0;

    for (pair<int, int> edge : edges) {
        cons[edge.first].push_back(edge.second);
        cons[edge.second].push_back(edge.first);
    }

    for (pair<int, int> edge : edges) {
        if (exVerts.count(edge.first) == 0 && exVerts.count(edge.second) == 0) {
            if (cons[edge.first].size() != 2) continue;
            //cout << endl << endl << edge.first << " ";
            int cur = edge.second, last = edge.first;
            bool b = true;
            exVerts.insert(edge.first);
            while (cur != edge.first) {
                //cout << cur << "(" << cons[cur].size() << ") ";
                if (exVerts.count(cur)) { b = false; break; }
                exVerts.insert(cur);
                if (cons[cur].size() != 2) { b = false; break; }
                else {
                    if (cons[cur][0] == last) {
                        last = cur;
                        cur = cons[cur][1];
                    } else {
                        last = cur;
                        cur = cons[cur][0];
                    }
                }
            }
            if (b)
                ret++;
        }
    }

    cout << ret << endl;
}
