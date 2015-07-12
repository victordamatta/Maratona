
#include <stdio.h>

using namespace std;

int main(){
    int n, i=0, j=1;
    scanf("%d", &n);

    printf("%d ", i);
    printf("%d ", j);
    for (int x=0; x<n-2; x++){
        if (x<n-3){
            if (i<j){
                i=i+j;
                printf("%d ", i);
            } else {
                j=i+j;
                printf("%d ", j);
            }
        } else {
            if (i<j){
                i=i+j;
                printf("%d\n", i);
            } else {
                j=i+j;
                printf("%d\n", j);
            }

        }
    }

    return 0;
}


