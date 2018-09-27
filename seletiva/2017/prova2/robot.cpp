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
char maze[300][300];
int ii[] = {0, -1, 0, 1};
int jj[] = {1, 0, -1, 0};

int right (int x) {
    return (x + 3) % 4;
}

int front (int x) {
    return x;
}

int left (int x) {
    return (x + 1) % 4;
}

int back (int x) {
    return (x + 2) % 4;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cout << t << endl;
    while (t--) {
        f (300, i) {
            f (300, j) {
                maze[i][j] = '#';
            }
        }
        int i = 150;
        int j = 150;

        int lm = 150, rm = 150, tm = 150, bm = 150;
        int ori = 0;

        string list;
        cin >> list;

        maze[i][j] = '.';
        for (char c : list) {
            if (c == 'R') {
                maze[i + ii[right(ori)]][j + jj[right(ori)]] = '.';
                i += ii[right(ori)];
                j += jj[right(ori)];
                ori = right (ori);
            }
            else if (c == 'F') {
                maze[i + ii[right(ori)]][j + jj[right(ori)]] = '#';
                maze[i + ii[front(ori)]][j + jj[front(ori)]] = '.';
                i += ii[front(ori)];
                j += jj[front(ori)];
                ori = front (ori);
            }
            else if (c == 'L') {
                maze[i + ii[right(ori)]][j + jj[right(ori)]] = '#';
                maze[i + ii[front(ori)]][j + jj[front(ori)]] = '#';
                maze[i + ii[left(ori)]][j + jj[left(ori)]] = '.';
                i += ii[left(ori)];
                j += jj[left(ori)];
                ori = left (ori);
            }
            else {
                maze[i + ii[right(ori)]][j + jj[right(ori)]] = '#';
                maze[i + ii[front(ori)]][j + jj[front(ori)]] = '#';
                maze[i + ii[left(ori)]][j + jj[left(ori)]] = '#';
                maze[i + ii[back(ori)]][j + jj[back(ori)]] = '.';
                i += ii[back(ori)];
                j += jj[back(ori)];
                ori = back (ori);
            }

            lm = min (lm, j);
            rm = max (rm, j);
            tm = min (tm, i);
            bm = max (bm, i);
        }

        cout << bm - tm + 3 << " " << rm - lm + 2 << endl;
        for (int i = tm-1; i <= bm+1; i++) {
            for (int j = lm; j <= rm+1; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
}
