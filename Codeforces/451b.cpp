#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<long int> v1, v2;
    long int n, aux, cont=1, c1=1, c2;
    scanf("%ld", &n);
    for(long int i=0; i<n; i++){
        scanf("%ld", &aux);
        v1.push_back(aux);
        v2.push_back(aux);
    }
    sort(v2.begin(), v2.end());
    vector<long int>::iterator i1, i12, i2, i13;
    i1 = v1.begin();
    i2 = v2.begin();
    while(*i1==*i2 && i1!=v1.end()){
        i1++;
        i2++;
        c1++;
    }
    if(i1==v1.end())
        printf("yes\n1 1\n");
    else{
        i12 = v1.end() - 1;
        i2 = v2.end() - 1;
        c2 = n;
        while(*i12==*i2 && i12!=v1.begin()-1){
            i12--;
            i2--;
            c2--;
        }
        reverse(i1, i12+1);
        i13 = v1.begin();
        i2 = v2.begin();
        while(i13!=v1.end() && cont){
            if(*i13 != *i2){
                printf("no\n");
                cont = 0;
            }
            i13++;
            i2++;
        }
        if(cont){
            printf("yes\n%ld %ld\n", c1, c2);
        }
    }
}
