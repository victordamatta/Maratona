#include <iostream>
#include <stdio.h>
using namespace std;
int balance(int small[], int big[][3], int bigsize, int which){
    int balancetot = 0;
    balancetot += small[which];
    for(int i = 0; i<bigsize; i++){
        if(big[i][0]==which+1){
            balancetot -= big[i][2];
        }else if(big[i][1]==which+1){
            balancetot += big[i][2];
        }
    }
    return balancetot;
}

int main()
{
    int debentures[20][3];
    int reserves[20];
    int b, n, ok;
    do{
        ok = 1;
        scanf("%d %d", &b, &n);
        for (int i = 0; i<b; i++){
            scanf("%d", &reserves[i]);
        }
        for(int j = 0; j<n; j++){
            scanf("%d %d %d", &debentures[j][0], &debentures[j][1], &debentures[j][2]);
        }
        for (int k = 0; k<b && ok==1; k++){
            if(balance(reserves, debentures, n, k)<0){
               ok = 0;
            } 
        }
        if(b>0){
            if (ok == 1){
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }while(b!=0 || n!=0);
    return 0;
}
