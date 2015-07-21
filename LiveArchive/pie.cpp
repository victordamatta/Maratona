#include <cstdio>
#include <math.h>
/*
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    int t;
    double pi = 3.14159265359;
    scanf("%d", &t);
    while(t--){
        int n, f, max=0;
        int pies[10500];
        scanf("%d%d", &n, &f);
        f++;
        f(n, i){
            scanf("%d", &pies[i]);
        }
        double mid, hi, lo;
        int aux;
        lo = 0.0;
        hi = pi*10000*10000+100;
        while((hi-lo)>0.00001){
            mid = (lo+hi)/2;
            aux = 0;
            f(n, i){
                aux += floor(pi*pies[i]*pies[i]/mid);
            }
            if(aux >= f){
                lo = mid;
            }
            else{
                hi = mid-0.00001;
            }
        }
        printf("%.4lf\n", lo);
    }
}
