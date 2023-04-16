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

vector<int> winner(vector<int> a, int b) {
    int t = a[0];
    for (int i = 0; i < a.size() - 1; i++)
        a[i] = a[i + 1];
    a[a.size() - 1] = b;
    a.push_back(t);
    return a;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k1, k2;
    cin >> n >> k1;
    vector<int> a(k1);
    cin >> a >> k2;
    vector<int> b(k2);
    cin >> b;

    for (int i = 0; i < n * 100; i++) {
        if (k1 == 0) {
            cout << i << " " << 2 << endl;
            return 0;
        } else if (k2 == 0) {
            cout << i << " " << 1 << endl;
            return 0;
        } else {
            if (a[0] > b[0]) {
                a = winner(a, b[0]);
                k1++;
                k2--;
                b.erase(b.begin());
            } else {
                b = winner(b, a[0]);
                k1--;
                k2++;
                a.erase(a.begin());
            }
        }

    }
    cout << -1 << endl;
    

    return 0;
}

