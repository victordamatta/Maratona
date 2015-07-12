
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, c, xi, xj, ans;
    do{
        scanf("%d %d ", &a, &c);
        if(a==0) break;
        scanf("%d ", &xi);
        ans = a-xi;
        for(int x = 1; x<c; x++){
            scanf("%d ", &xj);
            if(xj<xi){
                ans += xi-xj;
            }
            xi = xj;
        }
        printf("%d\n", ans);
    }while(a!=0 && c!=0);
    
    return 0;
}

