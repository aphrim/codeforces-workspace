//Category: 1400
//Link: https://codeforces.com/problemset/problem/489/C
//Complexity: O(n)
#include <bits/stdc++.h>
#define int long long int

using namespace std;

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

string minN(int length, int sum) {
    if (sum == 0 && length == 1) return "0";
    if (sum == 0 || length * 9 < sum) return "-1";
    string ret = "";
    int curSum = 0;
    while (ret.size() < length) { 
        int dig = max(0ll, (int) (sum - curSum - (9 * (length - ret.size() - 1))));
        if (dig == 0 && ret.size() == 0) dig = 1;
        ret += dig + '0';
        curSum += dig;
    }
    if (curSum > sum) return "-1";
    return ret;
}

string maxN(int length, int sum) {
    if (sum == 0 && length == 1) return "0";
    if (sum == 0 || length * 9 < sum) return "-1";
    string ret = "";
    int curSum = 0;
    while (ret.size() < length) {
        int dig = min(9ll, sum - curSum);
        ret += dig + '0';
        curSum += dig;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int length, sum;
    cin >> length >> sum;
    cout << minN(length, sum) << " " << maxN(length, sum) << endl;
}
