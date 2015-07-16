#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 10007
#define OO INT_MAX
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int vpd[100007][3];
int hs[100007], xs[100007];
int n;

int pd(int k, int fb){
    if(k==n) return 0;
    if(vpd[k][fb]!=-1) return vpd[k][fb];

    int rs;
    if(fb) rs = xs[k]-xs[k-1]-hs[k-1];
    else rs = xs[k]-xs[k-1];

    if(hs[k] < rs){
        vpd[k][fb] = 1 + pd(k+1, 0);
    }
    else if(hs[k] < xs[k+1]-xs[k]){
        vpd[k][fb] = max(1 + pd(k+1, 1), pd(k+1, 0));
    }
    else{
        vpd[k][fb] = pd(k+1, 0);
    }

    return vpd[k][fb];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    mset(vpd, -1);
    f(n){
        cin >> xs[i] >> hs[i];
    }
    xs[n] = INT_MAX;
    int ans = pd(1, 0);

    cout << ans + 1 << endl;
}
