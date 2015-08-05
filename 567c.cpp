#include <bits/stdc++.h>
using namespace std;

struct el{
    int val;
    int pos;
};
el vet[300000];

bool comp(el a, el b){
    if(a.val!=b.val){
        return a.val < b.val;
    }
    return a.pos < b.pos;
}

int lb(int l, int r, int t){
    if(l>r) return -1;
    if(l==r && vet[l].val==t) return l;
    if(l==r) return -1;
    int mid = (l+r)/2;
    if(vet[mid].val==t) return lb(l, mid, t);
    if(vet[mid].val < t) return lb(mid+1, r, t);
    return lb(l, mid-1, t);
}
int ub(int l, int r, int t){
    if(l>r) return -1;
    if(l==r && vet[l].val>t) return l;
    if(l==r) return -1;
    int mid = (l+r)/2;
    if(vet[mid].val>t) return ub(l, mid, t);
    if(vet[mid].val <= t) return ub(mid+1, r, t);
}
int ubp(int l, int r, int t){
    if(l>r) return -1;
    if(l==r && vet[l].pos>t) return l;
    if(l==r) return -1;
    int mid = (l+r)/2;
    if(vet[mid].pos>t) return ubp(l, mid, t);
    if(vet[mid].pos <= t) return ubp(mid+1, r, t);
}

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int aux, maxi=0;
    for(int i=0; i<n; i++){
        cin >> aux;
        vet[i].val = aux;
        vet[i].pos = i;
        if(aux % k*k == 0){
            aux /= k*k;
            if(aux > maxi) maxi = aux;
        }
    }
    sort(vet, vet+n, comp);
    int ans=0, i=0;
    while(i < n && vet[i].val <= maxi){
        int aux2, aux3;
        aux = lb(i+1, n-1, vet[i].val*k);
        if(aux==-1){
            i++;
            continue;
        }
        aux2 = ub(i+1, n-1, vet[i].val*k);
        if(aux2==-1) aux2 = n;
        aux3 = ubp(aux, aux2-1, vet[i].pos);
        int aux22, aux32;
        for(int j=aux3; j<aux2; j++){
            aux = lb(j+1, n-1, vet[j].val*k);
            if(aux==-1){
                continue;
            }
            aux22 = ub(j+1, n-1, vet[j].val*k);
            if(aux22==-1) aux22 = n;
            aux32 = ubp(aux, aux22-1, vet[j].pos);
            ans += aux22-aux32;
        }
        i++;
    }
    cout << ans << "\n";
    return 0;
}
