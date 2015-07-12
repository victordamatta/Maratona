#include <stdio.h>
long int bsearch(long int target, long int lo, long int hi, long int * ar){
    long int mid = (lo+hi)/2;
    if(target==ar[mid])
        return 1;
    if(lo==hi)
        return 0;
    if(target<ar[mid])
        return bsearch(target, lo, mid-1, ar);
    if(target>ar[mid])
        return bsearch(target, mid+1, hi, ar);
}

int main(){
    long int n, i;
    long int nums[100000], k, perf;
    scanf("%ld", &n);
    for(i=0;i<n;i++)
        scanf("%ld", &nums[i]);
    scanf("%ld", &k);
    for(i=0; i<n; i++){
        perf = nums[i];
        if(bsearch(k-perf, i+1, n-1, nums)){
            printf("%ld %ld\n", perf, k-perf);
            break;
        }
    }
    return 0;
}
