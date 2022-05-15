//Category: 1300
//Time complexity: O(n)
//Link: https://codeforces.com/problemset/problem/1676/G
//Note: Recursive DFS

#include <bits/stdc++.h>
#define int long long int

using namespace std;

struct TN {
    int val;
    int index;
    vector<TN*> children;
    TN* parent;
};



pair<int, pair<int, int>> rec(TN* node) {
    pair<int, pair<int, int>> ret;
    for (TN* child : node->children) {
        pair<int, pair<int, int>> res = rec(child);
        ret.first += res.first;
        ret.second.first += res.second.first;
        ret.second.second += res.second.second;
    }

    if (node->val == 'W') ret.second.first++;
    else ret.second.second++;
    if (ret.second.first == ret.second.second && ret.second.first >= 1) ret.first++;

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        map<int, TN*> treeMap;
        treeMap[1] = new TN();

        int n;
        cin >> n;

        int x = 1;


        while(n-->1) {
            int a;
            cin >> a;
            TN* node = new TN();
            node->index = ++x;
            treeMap[a]->children.push_back(node);
            treeMap[x] = node;
        }

        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i];
            treeMap[i+1]->val = c;
        }

        cout << rec(treeMap[1]).first << endl;
        for (auto it : treeMap)
            delete it.second;
    }
}
