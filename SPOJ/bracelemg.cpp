#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string bra, pat;
    char s1[10000], s2[10000];//, total[20000];
    int n;
    scanf("%d", &n);
    while(n--){
        scanf(" %s %s", s1, s2);
        pat = s1;
        bra = s2;
        bra += bra;
        if(bra.find(pat)!=string::npos){
            printf("S\n");
        }
        else{
            reverse(bra.begin(), bra.end());
            if(bra.find(pat)!=string::npos){
                printf("S\n");
            }
            else
                printf("N\n");
        }
    }
    return 0;
}
