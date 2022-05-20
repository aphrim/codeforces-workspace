//Category: 1500
//Complexity: Complicated, Will leave to figure out for later. Should be O(n) I think though.
//Link: https://codeforces.com/contest/580/problem/C
//Note: DFS.
#include <bits/stdc++.h>
#define int long long int

using namespace std;

struct TreeNode {
    vector<TreeNode*> children;
    bool hasCat;
    int node;
};

int m;

set<int> visited;

int dfs(TreeNode* node, int consecutive) {
    if (visited.count(node->node) == 1) return 0;
    if ((consecutive == m) && node->hasCat) return 0;
    if (node->children.size() <= 1 && node->node != 1) return 1;

    visited.insert(node->node);

    if (node->hasCat) consecutive++;
    else consecutive = 0;

    int ret = 0;

    for (TreeNode* child : node->children) {
        ret += dfs(child, consecutive);
    }


    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> m;
    map<int, TreeNode*> nodes;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; 
        nodes[i+1] = new TreeNode();
        nodes[i+1]->hasCat = a == 1;
        nodes[i+1]->node = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
        nodes[y]->children.push_back(nodes[x]);
    }

    if (nodes[1]->children.size() == 0)
        cout << 0 << endl;
    else
        cout << dfs(nodes[1], 0) << endl;

    for (auto it: nodes) delete it.second;
}
