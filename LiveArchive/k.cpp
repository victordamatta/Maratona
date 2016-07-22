#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int count = 0;
    string p;
    while (cin >> p) {
        if (p[7] == '+')
            count += 1;
        else
            count -= 1;
    }
    cout << count << endl;
}
