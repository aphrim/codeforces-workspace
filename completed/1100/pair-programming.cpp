#include <bits/stdc++.h>

//#define USACO

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

#ifdef USACO
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n), b(m);
        cin >> a >> b ; 

        vector<int> ret;

        int i = 0, j = 0;

        bool flag = false;
        while (i < n && j < m) {
            if (a[i] == 0) {
                ret.push_back(0);
                k++, i++;
            } else if (a[i] <= k) ret.push_back(a[i++]);
            else if (b[j] == 0) {
                ret.push_back(0);
                k++, j++;
            } else if (b[j] <= k) ret.push_back(b[j++]);
            else {
                flag = true;
                break;
            }
        }
        while (i < n) {
            if (a[i] == 0) {
                ret.push_back(0);
                i++, k++;
            } else if (a[i] <= k) {
                ret.push_back(a[i]);
                i++;
            } else {
                flag = true;
                break;
            }
        }

        while (j < m) {
            if (b[j] == 0) {
                ret.push_back(0);
                j++, k++;
            } else if (b[j] <= k) {
                ret.push_back(b[j]);
                j++;
            } else {
                flag = true;
                break;
            }
        }
        if (flag) cout << -1 << endl;
        else cout << ret << endl;
    }
}

