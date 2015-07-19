#include <cstdio>
using namespace std;

int main(){
    long int n, t, times[100005], sum, f, s, max;
    scanf("%ld%ld", &n, &t);
    for(long int i = 0; i<n; i++){
        scanf("%ld", &times[i]);
    }
    max = 0;
    sum = 0;
    f = 0;
    for(s = 0; s<n; s++){
        if(sum+times[s]>t){
            sum += times[s];
            while(sum>t){
                sum -= times[f];
                f++;
            }
        }
        else sum += times[s];

        if(s-f+1>max) max = s-f+1;
    }
    printf("%ld\n", max);

}
