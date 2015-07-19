
#include <cstdio>
#include <set>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    long int n, k, t, a;
    set<long int> s;
    scanf("%ld%ld", &n, &k);
    s.insert(1);
    t = 1;
    printf("1");
    a = 0;
    while(s.size()<n){
        a = 0;
        while(a == 0){
            a=1;
            for(long int i = k; i>0 && a; i--){
                if(t+i<=n && s.find(t+i)==s.end()){
                    s.insert(t+i);
                    t = t+i;
                    printf(" %d", t);
                    a = 0;
                }
            }
        }
        a = 0;
        while(a == 0){
            a=1;
            for(long int i = k; i>0 && a; i--){
                if(t-i>1 && s.find(t-i)==s.end()){
                    s.insert(t-i);
                    t = t-i;
                    printf(" %d", t);
                    a = 0;
                }
            }
        }
    }
    printf("\n");
}
