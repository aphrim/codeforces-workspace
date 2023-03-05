//USACO being poopy and marking test case as wa even though test case data response is same as expected
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
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
#endif

    map<string, int> c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        c[s] += x;
    }


    vector<string> amounts;
    for (pair<string, int> p : c) {
        amounts.push_back(p.first);
    }

    sort(amounts.begin(), amounts.end(), [&](string a, string b) {
        return (c[a] < c[b]);
    });

    if (c[amounts[0]] == c[amounts.back()])
        cout << "Tie \n";
    else {
        int first = c[amounts[0]], second = INT_MAX;
        string secondName;
        map<int, int> counts;
        int i;
        for (i = 1; i < amounts.size(); i++) {
            if (c[amounts[i]] != first) {
                second = min(second, c[amounts[i]]);
                if (second == c[amounts[i]])
                    secondName = amounts[i];
            }
            counts[c[amounts[i]]]++;
        }
        if (counts[second] > 1 || second == INT_MAX)
            cout << "Tie \n";
        else
            cout << secondName << endl;
    }
}
