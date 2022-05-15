#include <bits/stdc++.h>

using namespace std;

struct Vec3 {
    int x;
    int y;
    int z;
};

int main() {
    int vecCount;
    cin >> vecCount;
    Vec3 sum{0, 0, 0};
    while (vecCount-->0) {
        Vec3 n;
        cin >> n.x >> n.y >> n.z;
        sum.x += n.x;
        sum.y += n.y;
        sum.z += n.z;
    }

    cout << ((sum.x == 0 && sum.y == 0 && sum.z == 0) ? "YES" : "NO") << endl;
    
}
