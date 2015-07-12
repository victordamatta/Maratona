#include <stdio.h>
int main(){
    int m, s, s2, c=0, aux;
    scanf("%d%d", &m, &s);
    s2 = s;
    if(s==0 && m==1)
        printf("0 0\n");
    else if(s==0 || s>9*m)
        printf("-1 -1\n");
    else{
        aux = s2-9*(m-1);
        if(aux>0){
            printf("%d", aux);
            s2 -= aux;
        }
        else{
            printf("1");
            s2 -= 1;
        }
        c++;
        while(c<m){
            aux = s2-9*(m-c-1);
            if(aux<=0)
                printf("0");
            else{
                printf("%d", aux);
                s2 -= aux;
            }
            c++;
        }
        printf(" ");
        c = 0;
        while(c<m){
            if(s>9){
                printf("9");
                s -= 9;
            }
            else{
                printf("%d", s%10);
                s=0;
            }
            c++;
        }
        printf("\n");
    }
    return 0;
}
