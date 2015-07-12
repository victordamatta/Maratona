#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float l, c, r1, r2, help;
    scanf("%f %f %f %f", &l, &c, &r1, &r2);
    while(l!=0){
        if(r2<r1){
            help = r2;
            r2 = r1;
            r1 = help;
        }
        if((2*r2)>c || (2*r2)>l){
            printf("N\n");
        } else {
            if((r1+r2)>sqrt((l-r2-r1)*(l-r2-r1)+(c-r2-r1)*(c-r2-r1)))
                printf("N\n");
            else 
                printf("S\n");
        }
        scanf("%f %f %f %f", &l, &c, &r1, &r2);
    }
}
