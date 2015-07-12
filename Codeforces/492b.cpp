#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<long int> v;
    long int l, aux;
    int n;
    float dif1, dif2, dif3, ans;
    scanf("%d %ld", &n, &l);
    for(long int i=0; i<n; i++){
        scanf("%ld", &aux);
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    dif1 = *v.begin();
    dif3 = l - *(v.end()-1);
    dif2 = 0;
    for(vector<long int>::iterator t = v.begin()+1; t<v.end(); t++){
        aux = *t - *(t-1);
        if(aux>dif2) dif2 = aux;
    }
    dif2 /= 2;
    ans = max(dif1, max(dif2, dif3));
    printf("%.10f\n", ans);
    return 0;
}
