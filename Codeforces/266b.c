#include <stdio.h>
int main(){
    int t, n, i;
    char q[100], temp;
    scanf("%d%d", &n, &t);
    for(i=0; i<n; i++){
        scanf(" %c", &q[i]);
    }
    while(t>0){
        for(i=0; i<n-1; i++){
            if(q[i]<q[i+1]){
                temp = q[i];
                q[i] = q[i+1];
                q[i+1] = temp;
                i++;
            }
        }
        t--;
    }
    for(i=0; i<n; i++){
        printf("%c", q[i]);
    }
    printf("\n");
}
