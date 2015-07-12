#include <stdio.h>
using namespace std;

int main(){
    int n, x1, x2, counter, xinit, pass;
    scanf("%d", &n);
    while(n!=0){
        pass = 0;
        xinit = 0;
        counter = 0;
        scanf("%d", &x1);
        if(x1==0) xinit++;
        else pass = 1;
        for(int x = 1; x<n; x++){
            scanf("%d", &x2);
            if(x2==0 && pass==0) xinit++;
            if(x2==1 && pass==0) pass = 1;
            if(x1==0 && x2==0){
                counter++;
                x1=1;
            }
            else x1 = x2;
        }
        if(xinit%2!=0 && x1==0) counter++;
        scanf("%d", &n);
        printf("%d\n", counter);
    }
}
