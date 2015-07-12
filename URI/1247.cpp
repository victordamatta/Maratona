
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    float d, vf, vg;
    while(scanf("%f %f %f", &d, &vf, &vg)!=EOF){
        if (12/vf>=sqrt(d*d+144)/vg){
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    
    return 0;
}

