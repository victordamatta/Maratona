#include <stdio.h>
#include <ctype.h>
int main(){
    char str1[150], str2[150];
    int i=0, ok=1;
    scanf("%s %s", str1, str2);
    while(str1[i]!='\0' && ok){
        if(tolower(str1[i])>tolower(str2[i])){
            printf("1\n");
            ok = 0;
        }
        else if(tolower(str1[i])<tolower(str2[i])){
            printf("-1\n");
            ok = 0;
        }
        i++;
    }
    if(ok==1){
        printf("0\n");
    }
}
