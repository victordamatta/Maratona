
#include <cstdio>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    long int r, g, b, r2, g2, b2, ans=0, aux;
    scanf("%ld%ld%ld", &r, &g, &b);
    r2 = r%3;
    b2 = b%3;
    g2 = g%3;
    if(r==0 || g==0 || b==0){
        ans += r/3 + g/3 + b/3;
    }
    else if(r2==g2 && g2==b2){
        ans+=r2;
        r -= ans;
        g -= ans;
        b -= ans;
        ans += r/3 + g/3 + b/3;
    }
    else if(r2==0 && g2==0 && b2==0){
        ans += r/3 + g/3 + b/3;
    }
    else if(r2==g2){
        ans += r2;
        r-=r2;
        g-=r2;
        b-=r2;
        ans += r/3 + g/3 + b/3;
    }
    else if(r2==b2){
        ans += r2;
        r-=r2;
        g-=r2;
        b-=r2;
        ans += r/3 + g/3 + b/3;
    }
    else if(g2==b2){
        ans += g2;
        r-=g2;
        g-=g2;
        b-=g2;
        ans += r/3 + g/3 + b/3;
    }
    else{
        aux = min(min(r, b), g);
        ans += aux;
        r-=aux;
        b-=aux;
        g-=aux;
        ans += r/3 + g/3 + b/3;
    }
    printf("%ld\n", ans);
}
