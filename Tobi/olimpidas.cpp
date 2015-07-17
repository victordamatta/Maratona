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

struct country{
    int medals;
    int id;
} v[107];

bool comp(country a, country b){
    if(a.medals!=b.medals) return (a.medals > b.medals);
    else return (a.id < b.id);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, o, p, b;
    cin >> n >> m;
    country merda;
    merda.id = 0;
    merda.medals = 0;
    f(n+1){
        v[i] = merda;
    }
    f(m){
        cin >> o >> p >> b;
        v[o].id = o;
        v[o].medals++;
        v[p].id = p;
        v[p].medals++;
        v[b].id = b;
        v[b].medals++;
    }
    sort(v+1, v+1+n, comp);
    f(n){
        if(i+1!=n)
            cout << v[i+1].id << " ";
        else
            cout << v[i+1].id << "\n";
    }
}
