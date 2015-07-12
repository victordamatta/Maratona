#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int first[5], second[5], compat=1;
    scanf("%d %d %d %d %d ", &first[0], &first[1], &first[2], &first[3], &first[4]);
    scanf("%d %d %d %d %d ", &second[0], &second[1], &second[2], &second[3], &second[4]);
    for(int i = 0; i<5 && compat==1; i++){
        if(first[i]==second[i]){
            compat=0;
        }
    }
    if(compat==1) printf("Y\n");
    else printf("N\n");
}
