#include <bits/stdc++.h>
#define int long long int

#define USACO

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

vector<vector<char>> getLines(vector<vector<char>> board) {
    vector<vector<char>> ret;
    ret.push_back(board[0]);
    ret.push_back(board[1]);
    ret.push_back(board[2]);

    for (int i = 0; i < 3; i++)
    {
        ret.push_back(vector<char>());
        ret.back().push_back(board[0][i]);
        ret.back().push_back(board[1][i]);
        ret.back().push_back(board[2][i]);
    }

    ret.push_back(vector<char>{board[0][0], board[1][1], board[2][2]});
    ret.push_back(vector<char>{board[0][2], board[1][1], board[2][0]});

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef USACO
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
#endif

    vector<vector<char>> board(3, vector<char>(3));

    cin >> board;

    int countOnes = 0, countTwos = 0;

    vector<vector<char>> lines = getLines(board);

    set<char> singleWins;
    set<pair<char, char>> teamWins;

    for (auto line : lines)
        if ((line[0] == line[1]) && (line[1] == line[2])) {
            if (!singleWins.count(line[0])) {
                singleWins.insert(line[0]); 
                countOnes++;
            }
        }

    for (auto line : lines)
        if (!((line[0] == line[1]) && (line[1] == line[2]))) {
            if ((line[0] == line[1]) || (line[0] == line[2]) || (line[1] == line[2])) {
                char a, b;
                if (line[0] != line[1] && line[0] != line[2])
                    a = line[0], b = line[1];
                else if (line[1] != line[2] && line[1] != line[0])
                    a = line[1], b = line[2];
                else
                    a = line[2], b = line[0];
                if (b < a) {
                    char t = a;
                    a = b;
                    b = t;
                }
                if (!teamWins.count({a, b})) 
                    countTwos++;
                teamWins.insert({a, b});

            }
        }

    cout << countOnes << endl << countTwos << endl;

}
