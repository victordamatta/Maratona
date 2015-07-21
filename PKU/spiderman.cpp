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

int vpd[50][2000];
int choices[50];
int vet[50];
int m;

int pd(int k, int h){
    if(h==0 && k==m) return 0;
    if(k == m) return INT_MAX;
    if(h<0) return INT_MAX;
    if(vpd[k][h] != -1) return vpd[k][h];

    int up, down;
    up = max(h, pd(k+1, h+vet[k]));
    down = max(h, pd(k+1, h-vet[k]));
    
    if(up<down){
        vpd[k][h] = up;
    }
    else{
        vpd[k][h] = down;
    }

    return vpd[k][h];
}

void pd2(int k, int h){
    if(k==m) return;
    int up, down;
    up = pd(k+1, h+vet[k]);
    down = pd(k+1, h-vet[k]);

    if(up<down){
        choices[k] = 1;
        pd2(k+1, h+vet[k]);
    }
    else{
        choices[k] = 0;
        pd2(k+1, h-vet[k]);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ms(vpd, -1);
        cin >> m;
        f(m, i){
            cin >> vet[i];
        }
        int ans = pd(0, 0);
        if(ans == INT_MAX) cout << "IMPOSSIBLE\n";
        else{
            pd2(0, 0);
            f(m, i){
                if(choices[i]==1) cout << "U";
                else cout << "D";
            }
            cout << "\n";
        }
    }
}
