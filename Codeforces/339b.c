#include <stdio.h>
int main(){
    long int n, m, i, pval, val;
    long long int ans=0;
    scanf("%ld %ld", &n, &m);
    scanf("%ld", &pval);
    ans += pval-1;
    for(i=1; i<m; i++){
        scanf("%ld", &val);
        if(val>=pval)
            ans += val-pval;
        else
            ans += n-pval+val;
        pval = val;
    }
    printf("%lld\n", ans);
    return 0;
}
