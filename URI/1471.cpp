
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, r, input, keep = 0;
    while(scanf("%d", &n)!=EOF){
        scanf("%d", &r);
        int returned[r];
        for(int i = 0; i<r; i++){
            scanf("%d", &returned[i]);
        }
        if(n!=r){
            for(int j = 1;j<=n;j++ ){
                keep = 0;
                for(int x = 0; x<r&&keep==0;x++){
                    if(j==returned[x]){
                        keep = 1;
                    }
                }
                if(keep==0){
                    printf("%d ", j);
                }
            }
        } else {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

