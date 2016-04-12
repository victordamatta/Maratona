#include <cstdio>
using namespace std;

int main(){
    int t, max, k, sum, frds, counter;
    char ck;

    scanf("%d ", &t);
    for(int x = 0; x<t; x++){
        sum = 0;
        frds = 0;
        counter = 0;
        scanf("%d ", &max);
        for(int y = 0; y<max+1; y++){
            scanf("%c", &ck);
            k = ck - '0';
            if(k!=0){
                if(sum<counter){
                    frds += counter-sum;
                    sum = counter;
                }
                sum += k;
            }
            counter++;
        }
        printf("Case #%d: %d\n", x+1, frds);
    }
}
