//Category: 1500
//Link: https://codeforces.com/problemset/problem/1419/D2
//Complexity: O(nlogn)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    sort(a.begin(), a.end());

    vector<int> b(a.begin() + a.size() / 2, a.end());
    a = vector<int>(a.begin(), a.begin() + a.size() / 2);

    vector<int> retV;

    for (int i = 0; i < n / 2; i++) {
        retV.push_back(b[i]);
        retV.push_back(a[i]);
    }
    if (n % 2 == 1)
        retV.push_back(b.back());

    int retC = 0;

    for (int i = 1; i < retV.size() - 1; i++) {
        if (retV[i] < retV[i-1] && retV[i] < retV[i+1]) retC++;
    }

    cout << retC << endl << retV << endl;
}
