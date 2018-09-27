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
int n;
int vet[57];
int vpd[57][2000];

int choose2 (int x) {
    return (x*(x-1))/2;
}

int pd (int k, int sum) {
    if (sum < choose2 (k)) return OO;
    if (k == n && sum == choose2(n)) return 0;
    if (k == n) return OO;
    if (vpd[k][sum] != -1) return vpd[k][sum];

    int ans = OO;
    f (n, i) {
        ans = min (ans, abs (i - vet[k]) + pd (k+1, sum + i));
    }

    vpd[k][sum] = ans;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ms (vpd, -1);
        cin >> n;
        f (n, i) cin >> vet[i];
        sort (vet, vet + n);
        cout << pd (0, 0) << endl;
    }
}
