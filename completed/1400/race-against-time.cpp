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

bool b(float d, float t1, float t2) {
    if (t2 < t1) return (d > t1) || (d < t2);
    else return (d > t1 && d < t2);
}

float mo(float x) {
    if (x >= 360) x -= 360;
    return x;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;

    float secDegrees = s * 6;
    float minDegrees = mo(m * 6 + secDegrees / 60);
    float hDegrees = mo(h * 30 + minDegrees / 12);
    t1 = (t1 * 30) % 360;
    t2 = (t2 * 30) % 360;

    bool f1 = true, f2 = true;
    if (b(secDegrees, t1, t2)) f1 = false;
    if (b(minDegrees, t1, t2)) f1 = false;
    if (b(hDegrees, t1, t2)) f1 = false;

    if (b(secDegrees, t2, t1)) f2 = false;
    if (b(minDegrees, t2, t1)) f2 = false;
    if (b(hDegrees, t2, t1)) f2 = false;


    if (f1 || f2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

