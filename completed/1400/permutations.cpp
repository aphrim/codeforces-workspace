/*
ID: gregper1
TASK: 
LANG: C++
 */
#include <bits/stdc++.h>

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

int factorial(int x) {
    int ret = 1;
    while (x > 1) ret *= x, x--;
    return ret;
}

string perm(string s, vector<int> inds) {
    string ret = s;
    for (int i = 0; i < inds.size(); i++) ret[i] = s[inds[i]]; 
    return ret;
}

int toi(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret += (s[i] - '0') * pow(10, (s.size() - i - 1));
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> strings(n);
    cin >> strings;

    int itUpperBound = factorial(k);
    int ret = 1e9;
    vector<int> inds(k);
    for (int i = 0; i < k; i++) inds[i] = i;

    for (int i = 0; i <= itUpperBound; i++) {
        int ma = 0, mi = 1e9;
        for (string s : strings) ma = max(ma, toi(perm(s, inds))), mi = min(mi, toi(perm(s, inds)));
        next_permutation(inds.begin(), inds.end());
        ret = min(ret, ma - mi); 
    }

    cout << ret << endl;

    return 0;
}

