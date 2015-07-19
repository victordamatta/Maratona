#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define ms(x, v) memset(x, v, sizeof x)
#define MOD 1000000007
#define MAX 207
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, aux, tot;
int vpd[MAX][10007], vpd2[MAX];
vector<int> cars;

int pd(int k, int l, int r){
    if(l>tot) return -1;
    if(r>tot) return -1;
    if(k==n) return 0;
    if(vpd[k][l] != -1) return vpd[k][l];

    vpd[k][l] = max(1+pd(k+1, l+cars[k], r), 1+pd(k+1, l, r+cars[k]));

    return vpd[k][l];
}

void pd2(int k, int l, int r){
    if(k==n) return;

    int res1, res2;
    res1 = pd(k+1, l+cars[k], r);
    res2 = pd(k+1, l, r+cars[k]);
    if(res2>res1){
        vpd2[k] = 1;
        return pd2(k+1, l, r+cars[k]);
    }
    else{
        vpd2[k] = 0;
        return pd2(k+1, l+cars[k], r);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> tot;
    tot *= 100;
    n = 0;
    ms(vpd, -1);
    while(cin >> aux, aux!=0){
        cars.pb(aux);
        n++;
    }
    int ans;
    ans = pd(0, 0, 0);
    pd2(0, 0, 0);
    cout << ans << "\n";
    f(ans){
        if(vpd2[i]==0)
            cout << "port" << "\n";
        else
            cout << "starboard" << "\n";
    }
}
