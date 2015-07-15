#include <cstdio>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    char c, d, e;
    int ans, t;
    ans = 0;
    scanf("%d", &t);
    while(t--){
        scanf(" %c%c%c", &c, &d, &e);
        if(d=='+') ans++;
        else ans--;
    }
    printf("%d\n", ans);
}
