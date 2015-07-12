#include <cstdio>
#include <string>
using namespace std;
int main(){
    char org[50], alt[50];
    int n, o, i;
    scanf("%d", &n);
    while(n--){
        o = 1;
        i = 0;
        scanf("%s", org);
        alt[i] = tolower(org[i]);
        i++;
        while(org[i]!='\0' && o){
            alt[i] = tolower(org[i]);
            if(alt[i]<=alt[i-1]){
                o = 0;
            }
            i++;
        }
        if(o)
            printf("%s: O\n", org);
        else
            printf("%s: N\n", org);
    }
}
