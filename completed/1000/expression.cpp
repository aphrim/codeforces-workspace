#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int o1 = (n1 + n2) * n3;
    int o2 = n1 * n2 * n3;
    int o3 = n1 * (n2 + n3);
    int o4 = n1 + n2 + n3;

    cout << max(max(max(o1, o2), o3), o4) << endl;
    
}
