
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
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
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

struct num{
    int value;
    int pos;
};

int comp(num a, num b){
    return a.value < b.value;
}
int comp2(num a, num b){
    return a.pos < b.pos;
}
num seq[100007];

int find(int val, int n){
    int hi = n-1, lo = val-1, mid;
    while(lo <= hi){
        mid = (hi+lo)/2;
        if(seq[mid].value==val) return 1;
        if(seq[mid].value < val) lo = mid+1;
        else hi = mid - 1;
    }
    return 0;
}

/*
int lb(int val, int lo, int hi){
    int mid = (hi+lo)/2;
    if(lo==hi) return lo;
    if(seq[mid].value>=val) return lb(val, lo, mid);
    else return lb(val, mid+1, hi);
}
*/

int main(){
    std::ios::sync_with_stdio(false);
    int n, aux;
    int p[100007];
    int v[100007];
    int a=0;
    ms(p, 0);
    cin >> n;
    f(n, i){
        cin >> aux;
        seq[i].value = aux;
        seq[i].pos = i;
    }
    sort(seq, seq+n, comp);
    f(n, i){
        if(p[seq[i].value]) v[a] = p[seq[i].value];
        else p[seq[i].value] = i;
    }
    /*
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    */
    int cont = 0, s;
    for(int i=1; i<=n; i++){
        if(find(i, n)){
            continue;
        }
        seq[v[cont++]].value = i;
        /*
        int aux2 = lb(i, cont+1, n-1);
        seq[aux2].value = i;
        cont = aux;
        */
    }
    sort(seq, seq+n, comp2);
    cout << seq[0].value;
    for(int i=1; i<n; i++){
        cout << " " << seq[i].value;
    }
    cout << "\n";
}
