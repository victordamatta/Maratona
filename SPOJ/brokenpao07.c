#include <stdio.h>

int insert(long int vet, long int value, int size){
    long int temp;
    if(size==0) vet[0] = value;
    else{
        for(i=0; i<=size; i++){
            if(value<vet[i]){
                temp = vet[i];
                
            }
        }
    }
}

int main(){
    int n, k, i, tn=0;
    long int tam[10005], temp;
    long long int sum=0;
    scanf("%d", &n);
    scanf("%d", &k);
    
    for(i=0; i<k; i++){
        scanf("%ld", &temp);
        insert(tam, temp, i);
        sum += temp;
    }
    
    sum /= n;
    sum++;
    while(tn<n){
        sum--;
        tn = 0;
        for(i=0; i<k; i++)
            tn += tam[i]/sum;
    }
    printf("%lld\n", sum);
    return 0;
}
