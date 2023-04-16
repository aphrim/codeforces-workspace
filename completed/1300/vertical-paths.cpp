#include <bits/stdc++.h>
#define int long long int

//#define USACO

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename K, typename V> ostream& operator<<(ostream& out, map<K, V>& a) {for(pair<K, V> p : a) out << p.first << " " << p.second << '\n'; return out;};

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

typedef struct Node {
    vector<int> children;
};

vector<Node*> nodes;
vector<int> path;

void dfs(int cur) {
    path.push_back(cur + 1);
    if (nodes[cur]->children.size() == 0) {
        cout << path.size() << endl << path << endl;
    } else {
        dfs(nodes[cur]->children[0]);
        path = {};
        for (int i = 1; i < nodes[cur]->children.size(); i++) {
            dfs(nodes[cur]->children[i]);
        }
    }
    path = {};
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        nodes = vector<Node*>();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) nodes.push_back(new Node());
        for (int i = 0; i < n; i++) {
            int parent;
            cin >> parent;
            parent--;
            if (parent != i)
                nodes[parent]->children.push_back(i);
        }

        int count = 0;
        set<int> rootCandidates;
        for (int i = 0; i < n; i++) rootCandidates.insert(i);
        for (Node* node : nodes) {
            if (node->children.size() == 0) count++;
            for (int c : node->children) rootCandidates.erase(c);
        }

        int root = *rootCandidates.begin();
        cout << count << endl;
        path = {};
        dfs(root);
        cout << endl;
        for (Node* node : nodes) delete node;
    }
}
