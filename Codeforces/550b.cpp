#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long long int l, r, x, laux;
int n, aux;
long int ans, pr[16];

void pd2(int cp, long int td, long int ld, long int md){
    if(l<=td && td<=r && md-ld>=x){
        ans++;
    }
    if(td > r) return;
    if(cp==n) return;
    if(pr[cp] < ld){
        if(ld!=INT_MAX){
            if(ld>md)
                pd2(cp+1, td+pr[cp], pr[cp], ld);
        }
        else
            pd2(cp+1, td+pr[cp], pr[cp], md);
    }
    else if(pr[cp] > md){
        if(md!=0){
            if(md<ld)
                pd2(cp+1, td+pr[cp], md, pr[cp]);
        }
        else
            pd2(cp+1, td+pr[cp], ld, pr[cp]);
    }
    else
        pd2(cp+1, td+pr[cp], ld, md);
}

void pd(int cp, long int td, long int ld, long int md){
    if(l<=td && td<=r && md-ld>=x){
        pd2(cp, td, ld, md);
        return;
    }
    if(td > r) return;
    if(cp==n) return;
    pd(cp+1, td, ld, md);
    if(ld!=INT_MAX)
        md = max(ld, md);
    if(md!=0)
        ld = min(ld, md);
    ld = min(ld, pr[cp]);
    md = max(md, pr[cp]);
    pd(cp+1, td+pr[cp], ld, md);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> l >> r >> x;
    for(int i = 0; i<n; i++){
        cin >> pr[i];
    }
    ans = 0;
    pd(0, 0, INT_MAX, 0);
    cout << ans << "\n";
}
