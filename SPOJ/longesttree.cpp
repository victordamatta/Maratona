#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 10007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

vi tree[10007];
vector<bool> grau(10007, true);
int n;

int pd(int k){
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int a, b;
    while(cin >> a >> b){
        grau[b] = false;
        tree[a].pb(b);
    }
    int start;
    for(int i=1; i<=n; i++){
        if(grau[i]){
            start = i;
        }
    }
}
