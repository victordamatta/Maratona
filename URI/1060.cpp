

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int counter = 0;
    float num;
    for(int i = 0; i<6; i++){
        scanf("%f", &num);
        if (num>0) counter++;
    }
    printf("%d valores positivos\n", counter);

    return 0;
}

