//WA on TC 4, out of 16 TCs, what
#include <bits/stdc++.h>
#define int long long int

#define USACO

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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
#endif

    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<vector<int>> a(t, vector<int>(3));
    for (int i = 0; i < t; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y-1, z-1};
    }

    sort(a.begin(), a.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    set<int> patientZeroes, workingKs;
    for (int i = 0; i < n; i++) {
        for (int k = 1; k < 252; k++) {
            set<int> infected;
            vector<int> kRem(n, k);
            infected.insert(i);
            for (vector<int> v : a) {
                if (infected.count(v[1]) || infected.count(v[2])) {
                    int a, b;
                    if (infected.count(v[1])) a = v[1], b = v[2];
                    else a = v[2], b = v[1];
                    if (infected.count(a) && infected.count(b)) {
                        kRem[a]--, kRem[b]--;
                        continue;
                    }
                    if (kRem[a] > 0) {
                        kRem[a]--;
                        infected.insert(b);
                    }
                }
            }
            bool flag = true;
            for (int c = 0; c < s.size(); c++) {
                if ((s[c] == '1') != infected.count(c))
                    flag = false;
            }
            if (flag) {
                patientZeroes.insert(i);
                workingKs.insert(k);
            }
        }
    }

    int minK = INT_MAX, maxK = 0;

    for (int k : workingKs)
        minK = min(k, minK), maxK = max(maxK, k);

    cout << patientZeroes.size() << " ";
    cout << minK << " ";

    if (maxK == 251)
        cout << "Infinity" << endl;
    else cout << maxK << endl;
}
