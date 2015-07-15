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

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > v(101);
    vi v2(101, 0);
    f(m){
        int o, p, b;
        cin >> o >> p >> b;
        v2[o]++;
        v2[p]++;
        v2[b]++;
        v[o].first = -v2[o];
        v[o].second = o;
        v[p].first = -v2[p];
        v[p].second = p;
        v[b].first = -v2[b];
        v[b].second = b;
    }
    sort(v.begin()+1, v.begin()+1+n);
    for(int i=1; i<=n; i++){
        if(i==n)
            cout << v[i].second << "\n";
        else
            cout << v[i].second << " ";
    }
}
