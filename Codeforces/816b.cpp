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
int points[200007];

int main(){
    std::ios::sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;

    f(n, i) {
        int a, b;
        cin >> a >> b;
        points[a]+= 1;
        points[b+1]-= 1;
    }
    f (200000, i) {
        points[i+1] += points[i];
    }
    f (200001, i) points[i] = points[i] >= k;
    f (200000, i) {
        points[i+1] += points[i];
    }

    f (q, i) {
        int a, b;
        cin >> a >> b;
        cout << points[b] - points[a-1] << endl;
    }
}
