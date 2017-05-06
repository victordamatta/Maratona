#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int test;
    cin >> test;
    f (test, t) {
        string s;
        cin >> s;

        bool flipper = false;
        int pos = -1;
        for (int i = 1; i < s.size (); i++) {
            if (flipper) {
                s[i] = '9';
                continue;
            }
            if (s[i] < s[i-1]) {
                flipper = true;
                if (s[i-1] == '0') s[i-1] = '9';
                else s[i-1]--;
                pos = i-1;
                s[i] = '9';
            }
        }

        if (flipper) {
            for (int i = pos; i > 0; i--) {
                if (s[i] < s[i-1]) {
                    s[i] = '9';
                    if (s[i-1] == '0') s[i-1] = '9';
                    else s[i-1]--;
                }
            }
        }

        if (s[0] == '0') s = s.substr (1, s.size() - 1);

        cout << "Case #" << t+1 << ": ";
        cout << s << endl;
    }
}
