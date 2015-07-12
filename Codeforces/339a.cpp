#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int numbers[101], cont=0, i;
    char c;
    scanf("%d", &numbers[cont]);
    while(scanf("%c", &c)!=EOF){
        cont++;
        scanf("%d", &numbers[cont]);
    }
    sort(numbers, numbers+cont);
    for(i=0; i<cont; i++){
        if(i!=cont-1){
            printf("%d+", numbers[i]);
        }
        else
            printf("%d\n", numbers[i]);
    }
    return 0;
}
