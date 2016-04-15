#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <stack>
#define all(x) x.begin(), x.end()
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
const int MAX = 100007;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int n, m;
vi graph[MAX];
int p[MAX], w[MAX];
vpi edges;
int comps;

int find (int a) {
    if (a != p[a]) return p[a] = find (p[a]);
    return p[a];
}

void join (int a, int b) {
    if (find (a) == find (b)) return;
    else comps--;
    a = find (a);
    b = find (b);

    if (w[a] > w[b]) swap (a, b);
    p[a] = b;
    if (w[a] == w[b]) {
        w[b] += 1;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    comps = n;
    int a, b;
    f (n, i) {
        p[i+1] = i+1;
        w[i+1] = 1;
    }
    f (m, i) {
        cin >> a >> b;
        edges.pb (mp (a, b));
    }
    int te[MAX];
    f (m, i) {
        te[i] = 1;
    }
    int q;
    cin >> q;
    vi fe;
    f (q, i) {
        int aux;
        cin >> aux;
        aux--;
        te[aux] = 0;
        fe.pb (aux);
    }
    f (m, i) {
        if (te[i]) {
            join (edges[i].fst, edges[i].scd);
        }
    }
    stack<int> s;
    for (int i = fe.size ()-1; i >= 0; i--) {
        s.push (comps);
        join (edges[fe[i]].fst, edges[fe[i]].scd);
    }
    cout << s.top ();
    s.pop ();
    while (!s.empty ()) {
        cout << " " << s.top ();
        s.pop ();
    }
    cout << endl;
}
