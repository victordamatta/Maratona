#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, notes[10000], tmp, acc;
    long long int avg;
    while(scanf("%d ", &n)!=EOF){
        avg = 0;
        for(int i = 0; i < n; i++){
            scanf("%d ", &notes[i]);
            avg += notes[i];
        }
        if(avg%n==0){
            avg = avg/n;
            tmp = 0;
            acc = 0;
            while(notes[tmp]<avg){
                acc += avg-notes[tmp];
                tmp++;
            }
            printf("%d\n", acc+1);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
