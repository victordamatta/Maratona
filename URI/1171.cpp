
#include <iostream>
#include <stdio.h>

using namespace std;

void sortarray(int ar[], int len);

int main()
{
    int n;
    scanf("%d", &n);
    int numbers[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &numbers[i]);
    }

    sortarray(numbers, n);

    int x, prevx, xc = 1;
    for(int j = 0; j<n; j++){
        prevx = numbers[j];
        x = numbers[j+1];
        if(prevx == x){
            xc ++;
        }else{
            printf("%d aparece %d vez(es)\n", prevx, xc);
            xc = 1;
        }
    }
    
    return 0;
}

void sortarray(int ar[], int len){
    int keep = 0, chan;
    while(keep == 0){
        keep = 1;
        for (int h = 0; h<len; h++){
            if (h!=len-1){
                if(ar[h]>ar[h+1]){
                    chan = ar[h];
                    ar[h] = ar[h+1];
                    ar[h+1] = chan;
                    keep = 0;
                } 
            }
        }
    }
}
