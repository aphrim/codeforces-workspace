//Category: 1600
//Link: https://codeforces.com/contest/735/problem/D
//Complexity: O(1)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n == 2) cout << 1 << endl;
    else if (n == 3) cout << 1 << endl;
    else if (n == 4) cout << 2 << endl;
    else {
        if (isPrime(n)) cout << 1 << endl;
        else if (n % 2 == 0) cout << 2 << endl;
        else if (isPrime(n - 2)) cout << 2 << endl;
        else cout << 3 << endl;
    }
}
