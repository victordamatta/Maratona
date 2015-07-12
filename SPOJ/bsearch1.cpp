#include <cstdio>

long int bsearch(long int * vet, long int lo, long int hi, long int target){
    long int mid = (lo+hi)/2;
    if(vet[mid]==target) return mid;
    if(lo==hi && vet[lo] != target) return -1;
    if(vet[mid] > target) return bsearch(vet, lo, mid-1, target);
    if(vet[mid] < target) return bsearch(vet, mid+1, hi, target);
}

int main(){
    long int n, q;
    long int ar[100005], query;
    scanf("%ld %ld", &n, &q);

    for(int i=0; i<n; i++){
        scanf("%ld", &ar[i]);
    }

    for(int j = 0; j<q; j++){
        scanf("%ld", &query);
        printf("%ld\n", bsearch(ar, 0, n-1, query));
    }
}
