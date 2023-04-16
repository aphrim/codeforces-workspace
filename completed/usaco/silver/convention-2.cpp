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

struct Cow {
    int seniority;
    int t;
    int a;
};

struct set_cmp {
    bool operator() (const Cow lhs, const Cow rhs) const {
        return lhs.seniority > rhs.seniority; 
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].a >> cows[i].t; 
        cows[i].seniority = n - i;
    }

    sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
        return a.a < b.a;
    });

    int ret = 0, curEndTime = cows[0].a + cows[0].t;
    set<Cow, set_cmp> queue;
    int i = 1;
    while(true){
        int time = curEndTime;
        while (i < n && cows[i].a <= time) {
            queue.insert(cows[i]);
            i++;
        }
        if (i == n) break;
        if (queue.size() == 0) {
            queue.insert(cows[i]);
            curEndTime = cows[i].a;
            i++;
        }
        Cow cur = *queue.begin();
        ret = max(ret, curEndTime - cur.a);
        curEndTime = curEndTime + cur.t;
        queue.erase(cur);
    }
    cout << ret << endl;
    return 0;
}

