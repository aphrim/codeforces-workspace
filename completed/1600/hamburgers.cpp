//Category: 1600
//Link: https://codeforces.com/problemset/problem/371/C
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    int rb = 0, rs = 0, rc = 0;
    for (char c : s)
        switch(c) {
            case 'B':
                rb++;
                break;
            case 'S':
                rs++;
                break;
            default:
                rc++;
        }


    int ret = 0;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int n;
    cin >> n;

    while ((nb && rb) || (ns && rs) || (nc && rc)) {
        int price = max((rb - nb), 0ll) * pb + max((rs - ns), 0ll) * ps  + max((rc - nc), 0ll) * pc;
        if (price <= n) {
            n -= price;
            ret++;
            nb = max(0ll, nb - rb);
            ns = max(0ll, ns - rs);
            nc = max(0ll, nc - rc);
        } else break;
    }

    ret += n / (pb * rb + ps * rs + pc * rc);
    cout << ret << endl;
            

}
