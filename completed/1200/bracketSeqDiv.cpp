#include <bits/stdc++.h>

using namespace std;

bool isGoodSeq(string seq) {    
    if (seq.size() < 2) return false;
    int d = 0; 
    for (char c : seq) {
        if (c == '(') d++;
        else d--;
    }
    if (d == 0 && seq[0] == '(' && seq.back() == ')') return true;
    if (seq == string(seq.rbegin(), seq.rend())) return true;
    return false;
}

bool rmGoodSeq(string& seq, int& n) {
    for (int i = n; i < seq.size(); i++) {
        if (isGoodSeq(seq.substr(n, i - n + 1))) {
            n = i;
            return true;
        }
    }
    return false;
}

int main() {
    int tCount;
    cin >> tCount;
    while (tCount-- > 0) {
        int length;
        cin >> length;
        string seq;
        cin >> seq;

        int count = 0;
        int n = 0;

        while (n < length - 1) {
            if (seq[n] == '(' || seq[n] == ')' && seq[n + 1] == ')')
                n += 2;
            else {  
                int b = n + 1;
                while (b < length && seq[b] == '(')
                    b++;
                if (b == length)
                    break;
                n = b + 1;
            }
            count++;
        }

        cout << count << " " << length - n << endl;

    }
}
