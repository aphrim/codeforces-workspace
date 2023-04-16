#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //Prefix sum.
    //Find position of replace element in sorted array. Sum -= (prefixSum[n] - prefixSum[position]), Sum -= replaceElement * position
    //Find new position of updated element. Sum += newElement * position, Sum += (prefixSum[n] - prefixSum[position])


    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    map<int, int> indexMap;
    for (int i = 0; i < n; i++) {
        indexMap[a[i].second] = i;
    }

    int totalSum = 0;
    vector<int> prefixSum(n + 1);
    for (int i = 0; i < n; i++) {
        totalSum += a[i].first * (i + 1);
        prefixSum[i+1] = prefixSum[i] + a[i].first;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = a[i].first;
    int q;
    cin >> q;
    while (q--) {
        int newSum = totalSum;
        int i, j;
        cin >> i >> j;
        int oldInd = indexMap[i], newInd = lower_bound(v.begin(), v.end(), j) - v.begin();
        newSum -= oldInd * v[oldInd];
        newSum -= prefixSum.back() - prefixSum[oldInd];
        //^All correct

        newSum += (newInd + 1) * j;
        newSum += prefixSum.back() - prefixSum[newInd];
        if (oldInd >= newInd) newSum -= v[oldInd];
        else newSum -= j;
        cout << newSum << endl;
    }




    return 0;
}

