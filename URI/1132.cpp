
#include <stdio.h>

using namespace std;

int main(){
    int x, y, i, j, sum = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    if(x>y){i = y; j = x;} else {i = x; j = y;}
    
    while(i<=j){
        if(i%13!=0){
            sum+=i;
        }
        i++;
    }
    printf("%d\n", sum);

    return 0;
}
