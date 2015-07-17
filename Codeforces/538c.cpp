#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 10007
#define OO INT_MAX
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

set< pair<int, int> > s;
int n, m;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int aux, aux2;
    f(m){
        cin >> aux >> aux2;
        s.insert(mp(aux, aux2));
    }
    set<pair<int, int> >::iterator it = s.begin();
    int max, cur, prev, dcur, dprev, dif, ddif;
    dprev = (*it).first;
    prev = (*it).second;
    max = prev + dprev - 1;
    it++;
    while(it != s.end()){
        cur = (*it).second;
        dcur = (*it).first;
        dif = abs(cur-prev);
        ddif = dcur - dprev;
        if(dif>ddif){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        else ddif -= dif;
        if(ddif%2==1){
            ddif--;
        }
        if(cur > prev){
            aux = cur+ddif/2;
            if(aux>max) max = aux;
        }
        else{
            aux = prev+ddif/2;
            if(aux>max) max = aux;
        }
        prev = cur;
        dprev = dcur;
        it++;
    }
    aux = prev + n-dprev;
    if(aux>max) max = aux;
    cout << max << "\n";
}
