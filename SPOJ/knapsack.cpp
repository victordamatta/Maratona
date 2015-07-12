#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

num memoriza[2001][2001];
num n, s, w[2001], v[2001];

num mochila(num obj, num weight){
    if(obj==n)
        return 0;
    if(memoriza[obj][weight]!=-1){
        return memoriza[obj][weight];
    }
    num r1=0, r2=0;
    if(w[obj] <= weight)
        r1 = v[obj] + mochila(obj+1, weight-w[obj]);
    r2 = mochila(obj+1, weight);
    num resposta = max(r1, r2);
    memoriza[obj][weight] = resposta;
    return resposta;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> s >> n;
    for(int i = 0; i<n; i++){
        cin >> w[i] >> v[i];
        memoriza[i][0] = 0;
        for(int j = 1; j<=s; j++){
            memoriza[i][j] = -1;
        }
    }
    cout << mochila(0, s) << "\n";
}
