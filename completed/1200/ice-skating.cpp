/*
ID: gregper1
TASK: 
LANG: C++
 */
#include <bits/stdc++.h>
#define int long long int

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

int largeDiv(int a, int b) {
    return (a + b - 1) / b;
}

bool isPrime(int x) {
    if (x== 1) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

template<typename T>
set<T> intersection(set<T> a, set<T> b) {
    set<T> ret;
    for (T x : a) ret.insert(x);
    for (T x : b) ret.insert(x);
    return ret;
}

struct Node {
    int x;
    int y;
    vector<Node*> connections;
} ;


set<Node*> found;
set<Node*> dfs(Node* cur, set<Node*>& curComponent) {
    if (curComponent.count(cur)) return {}; 
    set<Node*> ret;
    curComponent.insert(cur);
    ret.insert(cur);
    for (Node* con : cur->connections) {
        ret = intersection(ret, dfs(con, curComponent));
    }
    return ret;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    vector<Node*> disjoint(n);
    for (int i = 0; i < n; i++) {
        disjoint[i] = new Node();
        cin >> disjoint[i]->x >> disjoint[i]->y;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (disjoint[i]->x == disjoint[j]->x || disjoint[i]->y == disjoint[j]->y) {
                disjoint[i]->connections.push_back(disjoint[j]); 
                disjoint[j]->connections.push_back(disjoint[i]); 
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (found.count(disjoint[i])) continue;
        set<Node*> curComponent = {};
        found = intersection(found, dfs(disjoint[i], curComponent));
        ret++;
    }

    cout << ret - 1 << endl;

    for (Node* node : disjoint) delete node;


    return 0;
}

