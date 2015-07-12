#include <cstdio>
#include <iostream>
using namespace std;

int triexists(int lo, int hi, int ar[100000], int s){
    int mid;
    mid = hi/2;
    while(lo<=hi){
        if(s>ar[mid]) lo=mid+1;
        else if(s<ar[mid]) hi=mid-1;
        else return true;
        mid = lo + (hi-lo)/2;
    }
    return false;
}

int main(){
    int points, distances[100000], n, counter;
    long long int sum;
    while(scanf("%d", &n)!=EOF){
        sum = 0;
        counter = 0;
        distances[0] = 0;
        for(int i = 0; i<n; i++){
            scanf("%d", &points);
            if(i!=n-1)
                distances[i+1] = distances[i] + points;
            sum += points;
        }
        if(sum%3==0){
            sum = sum/3;
            for(int j = 0; distances[j]<sum; j++)
                if(triexists(j+1, n-1, distances, distances[j]+sum))
                    if(triexists(j+1, n-1, distances, distances[j]+2*sum))
                        counter++;
        }
        printf("%d\n", counter);
    }
    return 0;
}
