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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        times.push_back({s, i});
        times.push_back({e, i});
    }
    sort(times.begin(), times.end());

    int ret = 0;
    int cur = 0, start = -1;
    set<int> enc;
    vector<int> aloneTime(n);
    aloneTime[0] = INT_MAX;
    for (int i = 0; i < times.size(); i++) {
        if (cur == 1) {
            aloneTime[*enc.begin()] += times[i].first - times[i - 1].first;
        }
        if (enc.count(times[i].second)) cur--, enc.erase(times[i].second);
        else cur++, enc.insert(times[i].second);
        if (cur > 0 && start == -1) start = times[i].first;
        if (cur == 0 && start != -1) {
            ret += times[i].first - start;
            start = -1;
        }
    }
    if (start != -1) {
        ret += times.back().first - start;
    }

    ret -= *min_element(aloneTime.begin(), aloneTime.end());
    cout << ret << endl;

    return 0;
}

