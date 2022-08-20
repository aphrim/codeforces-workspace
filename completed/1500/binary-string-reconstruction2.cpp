//Category: 1500
//Link: https://codeforces.com/contest/1352/problem/F
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

    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        stringstream ret;
        cin >> n0 >> n1 >> n2;

        char lC = '2';
        if (n2 > 0) {
            n2--;
            ret << "11";
            while (n2--) {
                ret << '1';
            }
            lC = '1';
        }

        if (n1 > 0) {
            while (n1 > 0) {
                if (lC == '0') { ret << '1'; n1--; }
                if (lC == '2') ret << '1';
                lC = '1';
                if (n1 > 0) {
                    n1--;
                    ret << '0';    
                    while (n0 > 0) {
                        ret << '0';
                        n0--;
                    }
                    lC = '0';
                }
            }
        }

        if (n0 > 0) {
            if (lC == '1') {
                n1--;
            }
            if (lC != '0') {
                ret << "00";
                n0--;
            }
            while (n0--) {
                ret << '0';
            }
            lC = '0';
        }

        cout << ret.str() << endl;
    }
}
