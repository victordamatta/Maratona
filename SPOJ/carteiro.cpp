#include <cstdio>

int bsearch(int * ar, int lo, int hi, int target){
    int mid = (hi+lo)/2;
    if(ar[mid]==target) return mid;
    if(ar[mid]>target) return bsearch(ar, lo, mid-1, target);
    if(ar[mid]<target) return bsearch(ar, mid+1, hi, target);
}

int main(){
    int n, m, cur, old, target, oltarget, ans=0;
    int houses[46000];
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &houses[i]);
    }

    scanf("%d", &target);
    oltarget = target;
    old = bsearch(houses, 0, n-1, target);
    ans+=old;
    for(int j=1; j<m; j++){
        scanf("%d", &target);
        if(oltarget < target){
            cur = bsearch(houses, old, n-1, target);
            ans+=cur-old;
            oltarget = target;
            old = cur;
        }
        else if(oltarget>target){
            cur = bsearch(houses, 0, old, target);
            ans += old-cur;
            oltarget = target;
            old = cur;
        }
    }
    printf("%d\n", ans);
}
