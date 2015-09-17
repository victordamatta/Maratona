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

int vols[101000];
int volb[101000];

int main(){
    std::ios::sync_with_stdio(false);
    int n, s;
    int p, q;
    char d;
    cin >> n >> s;
    ms(vols, 0);
    ms(volb, 0);
    int buy[10000];
    int sell[10000];
    int buys=0, sells=0;
    f(n, i){
        cin >> d >> p >> q;
        if(d=='B'){
            volb[p] += q;
            buy[buys++] = p;
        }
        else{
            vols[p] += q;
            sell[sells++] = p;
        }
    }
    sort(sell, sell+sells);
    sort(buy, buy+buys);
    int ant = -1;
    int aux=0, aux2=0;
    while(aux2 < sells){
        if(ant!=sell[aux2]) aux++;
        if(aux==s+1){
            break;
        }
        ant = sell[aux2];
        aux2++;
    }
    aux2--;
    ant = -1;
    while(aux2>=0) {
        if(ant == sell[aux2]){
            ant = sell[aux2];
            aux2--;
        }
        else{
            cout << "S " << sell[aux2] << " " << vols[sell[aux2]] << "\n";
            ant = sell[aux2];
            aux2--;
        }
    }
    buys--;
    ant = -1;
    while(buys>=0 && s>0) {
        if(ant==buy[buys]){
            ant = buy[buys];
            buys--;
        }
        else{
            cout << "B " << buy[buys] << " " << volb[buy[buys]] << "\n";
            ant = buy[buys];
            buys--;
            s--;
        }
    }
}
