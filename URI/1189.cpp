
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char O;
    scanf("%c", &O);
    float ans = 0, var;
    int counter = 0;
    for(int i = 0; i<12; i++){
        for(int j = 0; j<12; j++){
            scanf("%f", &var);
            if (i>j && i<11-j){
                ans += var;
                counter++;
            }
        }
    }
    
    if(O=='S'){
        printf("%.1f\n", ans);
    } else {
        printf("%.1f\n", ans/counter);
    }

    return 0;
}

