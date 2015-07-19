#include <iostream>
#include <cstring>
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

int n, ns[10007], nsnc[10007], mods[10007], aux;

int main(){
    ms(mods, -1);
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> ns[0];
    nsnc[0] = ns[0];
    mods[ns[0]%n] = 0;
    if(ns[0]%n==0){
        cout << "1\n" << ns[0] << "\n";
        return 0;
    }
    int fst=-1, scd=-1, hm=-1;
    for(int i=1; i<n; i++){
        cin >> aux;
        ns[i] = ns[i-1] + aux;
        nsnc[i] = aux;
        aux = mods[ns[i]%n];
        if(ns[i]%n==0){
            fst = -1;
            scd = i;
            hm = scd - fst;
            break;
        }
        else if(aux != -1){
            fst = mods[ns[i]%n];
            scd = i;
            hm = scd - fst;
            break;
        }
        else{
            mods[ns[i]%n] = i;
        }
    }
    if(scd==-1)
        cout << "0\n";
    else{
        cout << hm << endl;
        for(int i=fst+1; i<=scd; i++){
            cout << nsnc[i] << "\n";
        }
    }
}
