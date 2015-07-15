#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, a, tot, v[100005];

bool difbytwo(long int a, long int b){
    int x, y;
    x = min(a, b);
    y = max(a, b);
    while(x<b){
        x*=2;
    }
    if(x==b){return true;}
    x = min(a, b);
    while(y>x){
        y/=2;
    }
    if(y==x){return true;}
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    tot = 0;
    int ok = 1;
    cin >> v[0];
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(ok && !difbytwo(v[i], v[i-1]){
            ok = 0;        
        }
    }
    if(ok == 0){
    int a;
    for(int i=0; i<n; i++){
    a = v[i];
        while(a>1){
            tot++;
            a/=2;
        }
    }
    cout << tot << "\n";
    }
    else{
        
    }
}
