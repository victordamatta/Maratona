#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    long int n;
    long long int x, i;
    vector<bool> a(1000001, true);
    for(long int k=2; k<=1000; k++)
        if(a[k])
            for(long int h=k*k; h<=1000000; h+=k)
                a[h] = false;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==1)
            printf("NO\n");
        else{
            i = (long long int)sqrt(x);
            if(pow(i, 2)==x){
                if(a[i])
                    printf("YES\n");
                else 
                    printf("NO\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}
