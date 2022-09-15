//Category: 1500
//Link: https://codeforces.com/problemset/problem/1325/C
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

struct Node {
    vector<pair<Node*, int>> cons;
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<Node*>nodes(n);
    for (int i = 0; i < n; i++) nodes[i] = new Node();

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;

        nodes[a]->cons.push_back({nodes[b], i});
        nodes[b]->cons.push_back({nodes[a], i});
    }

    vector<int> ret(n-1, -1);
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i]->cons.size() == 1) {
            if (ret[nodes[i]->cons[0].second] == -1) {
                ret[nodes[i]->cons[0].second] = l;
                l++;
            }
        }
    }
    for (int& x : ret) if (x == -1) { x = l; l++; }

    cout << ret << endl;

    for (Node* n : nodes) delete n;

}
