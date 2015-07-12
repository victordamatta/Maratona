
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, counter, number;
    int start[24];
    int end[24];

    while(scanf("%d", &n)!=EOF){
        counter = 0;
        for(int i = 0; i<n; i++){
            scanf(" %d", &start[i]);
        }
        for(int x = 0; x<n; x++){
            scanf(" %d", &end[x]);
        }
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                if(end[j]==start[k]){
                    number = k;
                }
            }
            if(j==0){
                counter+=number;
            } else {
                for(int a = 0; a<number; a++){
                    for(int b = j+1; b<n; b++){
                        if(end[b]==start[a]) counter++;
                    }
                }
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}

