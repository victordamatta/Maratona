#include <cstdio>
using namespace std;

int main(){
    int t, x, r, c;
    
    scanf("%d ", &t);
    for(int i = 0; i<t; i++){
        scanf("%d %d %d", &x, &r, &c);
        if(x==1)
            printf("Case #%d: GABRIEL\n", i+1);
        else if(x==2)
            if((r*c)%2==0)
                printf("Case #%d: GABRIEL\n", i+1);
            else
                printf("Case #%d: RICHARD\n", i+1);
        else if(x==3)
            if(((r*c)%6)%3==0 && r>1 && c>1)
                printf("Case #%d: GABRIEL\n", i+1);
            else
                printf("Case #%d: RICHARD\n", i+1);
        else
            if(r>=3 && c>=3)
                if(r!=3 || c!=3)
                    printf("Case #%d: GABRIEL\n", i+1);
                else
                    printf("Case #%d: RICHARD\n", i+1);
            else
                printf("Case #%d: RICHARD\n", i+1);
    }
}
