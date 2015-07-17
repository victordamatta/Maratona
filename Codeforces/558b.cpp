#include <iostream>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, aux;

struct number{
    long int val;
    long int pos;
};
number vet[100005];
bool comp(number a, number b){
    return (a.val < b.val);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(long int i=0; i<n; i++){
        cin >> aux;
        number x;
        x.val = aux;
        x.pos = i;
        vet[i] = x;
    }
    sort(vet, vet+n, comp);
    long int num, times, cnum, ctimes, b, e, cb, ce;
    cnum = num = vet[0].val;
    ctimes = times = 1;
    cb = b = vet[0].pos;
    ce = e = cb;
    for(long int i=1; i<n; i++){
        if(vet[i].val==cnum){
            ctimes++;
            cb = min(cb, vet[i].pos);
            ce = max(ce, vet[i].pos);
        }
        else{
            cnum = vet[i].val;
            cb = vet[i].pos;
            ce = cb;
            ctimes = 1;
        }
        if(ctimes > times){
            num = cnum;
            times = ctimes;
            b = cb;
            e = ce;
        }
        else if(ctimes == times){
            if(ce-cb < e-b){
                num = cnum;
                times = ctimes;
                b = cb;
                e = ce;
            } 
        }
    }
    cout << b+1 << " " << e+1 << "\n";
}
