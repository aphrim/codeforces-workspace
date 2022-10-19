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

bool works(vector<string>& sol, vector<vector<string>>& rules) {
    map<string, int> inds;
    for (int i = 0; i < sol.size(); i++) {
        inds[sol[i]] = i;
    }

    for (vector<string> rule : rules) {
        if (abs(inds[rule[0]] - inds[rule[1]]) != 1)
            return false;
    }

    return true;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif

    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());

    int n;
    cin >> n;
    vector<vector<string>> rules(n, vector<string>(2));
    for (int i = 0; i < n; i++) {
        string _;
        cin >> rules[i][0] >> _ >> _ >> _ >> _ >> rules[i][1];
    }


    while (next_permutation(cows.begin(), cows.end())) {
        if (works(cows, rules))
            break;
    }

    for (string s : cows)
        cout << s << endl;

}
