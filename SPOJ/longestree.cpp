#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
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

vi tree[10007];
int dist[10007];
int n;

int main(){
    scanf("%d", &n);
    int aux, aux2, any;
    ms(dist, -1);
    f(n-1){
        scanf("%d%d", &aux, &aux2);
        tree[aux].pb(aux2);
        tree[aux2].pb(aux);
        any = aux;
    }
    dist[any] = 0;
    queue<int> q;
    q.push(any);
    int max = 0, nmax;
    int cur;
    do{
        cur = q.front();
        if(dist[cur] > max){
            max = dist[cur];
            nmax = cur;
        }
        q.pop();
        for(int i=0; i<tree[cur].size(); i++){
            if(dist[tree[cur][i]]==-1){
                q.push(tree[cur][i]);
                dist[tree[cur][i]] = dist[cur] + 1;
            }
        }
    }while(!q.empty());
    ms(dist, -1);
    dist[nmax] = 0;
    max = 0;
    q.push(nmax);
    do{
        cur = q.front();
        q.pop();
        if(dist[cur] > max){
            max = dist[cur];
            nmax = cur;
        }
        for(int i=0; i<tree[cur].size(); i++){
            if(dist[tree[cur][i]]==-1){
                q.push(tree[cur][i]);
                dist[tree[cur][i]] = dist[cur] + 1;
            }
        }
    }while(!q.empty());
    cout << max << endl;
}
