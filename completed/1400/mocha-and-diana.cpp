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

vector<vector<int>> edgesM, edgesD;
set<int> foundM, foundD;
vector<set<int>> cM, cD;

set<int>unn(set<int> a, set<int> b) {
    set<int> ret;
    for (int x : a) ret.insert(x);
    for (int x : b) ret.insert(x);
    return ret;
}

set<int> dfs(int cur, bool m) {
    if (m) foundM.insert(cur);
    else foundD.insert(cur);
    set<int> ret;
    if (m) {
        for (int edge : edgesM[cur])
            if (!foundM.count(edge))
                ret = unn(ret, dfs(edge, m));
    } else {
        for (int edge : edgesD[cur])
            if (!foundD.count(edge))
                ret = unn(ret, dfs(edge, m));
    }
    ret.insert(cur);      
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m1, m2;
    cin >> n >> m1 >> m2;
    edgesM = vector<vector<int>>(n + 1);
    edgesD = vector<vector<int>>(n + 1);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        edgesM[u].push_back(v);
        edgesM[v].push_back(u);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        edgesD[u].push_back(v);
        edgesD[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!foundM.count(i + 1))
            cM.push_back(dfs(i + 1, true));
    }
    for (int i = 0; i < n; i++) {
        if (!foundD.count(i + 1))
            cD.push_back(dfs(i + 1, false));
    }

    vector<pair<int, int>> cons;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int setMA, setMB, setDA, setDB; 
            for (int k = 0; k < cM.size(); k++) {
                if (cM[k].count(i)) setMA = k;
                if (cM[k].count(j)) setMB = k;
            }
            for (int k = 0; k < cD.size(); k++) {
                if (cD[k].count(i)) setDA = k;
                if (cD[k].count(j)) setDB = k;
            }
            if (setMA != setMB && setDA != setDB) {
                cons.push_back({i,j});
                cM[setMA] = unn(cM[setMA], cM[setMB]);
                cD[setDA] = unn(cD[setDA], cD[setDB]);
                cM.erase(cM.begin() + setMB);
                cD.erase(cD.begin() + setDB);
            }
        }
    }
    cout << cons.size() << endl;
    for (pair<int, int> p : cons) cout << p.first << " " << p.second << endl;


    return 0;
}

