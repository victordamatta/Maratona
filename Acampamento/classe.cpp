#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define mset(x, v) memset(x, v, sizeof x)
#define f(x) for(int i=0; i<x; i++)
#define MOD 1e9+7
#define MAX 10007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    vector<string> v;
    int n, k;
    string aux;
    cin >> n >> k;
    f(n){
        cin >> aux;
        v.pb(aux);
    }
    sort(all(v));
    cout << v[k-1] << "\n";
}
