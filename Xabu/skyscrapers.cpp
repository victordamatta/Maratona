#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
/*
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int ans[1000007];
ll hs[1000007];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        ll maxi = 0;
        f(n, i){
            cin >> hs[i];
            if(hs[i] > maxi) maxi = hs[i];
        }
        ms(ans, 0);
        for(ll i=1; i<n-1; i++){
            if(hs[i-1] > hs[i] && hs[i+1]>hs[i]){
                ans[hs[i]]++;
            }
            if(hs[i]>hs[i-1] && hs[i]>hs[i+1]){
                ans[hs[i]]--;
            }
        }
        if(hs[0]>hs[1]) ans[hs[0]]--;
        if(hs[n-1]>hs[n-2]) ans[hs[n-1]]--;
        ans[0] = 1;
        for(ll i=1; i<n; i++){
            ans[i] += ans[i-1];
        }

        ll aux;
        cin >> aux;
        if(aux < maxi)
            cout << ans[aux];
        else 
            cout << "0";
        for(ll i=1; i<d; i++){
            cin >> aux;
            if(aux < maxi)
                cout << " " << max(ans[aux], 0);
            else 
                cout << " " << "0";
        }
        cout << "\n";
    }
}
