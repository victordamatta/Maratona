#include <stdio.h>
int main(){
    int d, cont=1;
    while(scanf("%d", &d), d!=0){
        printf("Teste %d\n", cont);
        printf("%d %d %d %d\n", d/50, (d%50)/10, ((d%50)%10)/5, ((d%50)%10)%5);
        printf("\n");
        cont++;
    }
    return 0;
}
