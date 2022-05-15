//Category: 1300
//Complexity: O(1) (This is kinda cheating, bc it precomputes the set of numbers that are T-Primes
//Link: https://codeforces.com/problemset/problem/230/B
//Note: A T-Prime would be the square of a prime number.
#include <bits/stdc++.h>

using namespace std;

set<long long int> s;

bool isP(long long int n) {
    float sq = sqrt(n);
    for (int i = 2; i <= sq; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void preComp() {
    int m = pow(10, 6);
    s.insert(4);
    for (long long int i = 3; i < m; i += 2) {
        if (isP(i)) s.insert(i * i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preComp();
    int n;
    cin >> n;

    while(n-->0) {
        long long int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    

    
}
