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
#define aint(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int heap[10000007];

void insert(int node, int l, int r, int ind, int val){
    if(l==r){
        heap[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(ind <= mid) insert(2*node, l, mid, ind, val);
    else insert(2*node+1, mid+1, r, ind, val);

    heap[node] = heap[2*node]*heap[2*node+1];
}

int find(int node, int l, int r, int ini, int fim){
    if(l>=ini && r<=fim) return heap[node];
    if(ini>r || fim < l) return 1;
    int mid = (l+r)/2;
    return find(2*node, l, mid, ini, fim)*find(2*node+1, mid+1, r, ini, fim);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    while(cin.peek()!=EOF){
        cin >> n >> k;
        int aux, aux2;
        f(n, i){
            cin >> aux;
            if(aux > 0)
                insert(1, 0, n-1, i, 1);
            else if(aux < 0)
                insert(1, 0, n-1, i, -1);
            else
                insert(1, 0, n-1, i, 0);
        } 
        cin.get();
        char c;
        int ans;
        while(cin.peek()=='C' || cin.peek()=='P'){
            cin >> c >> aux >> aux2;
            if(c=='C'){
                if(aux2 > 0)
                    insert(1, 0, n-1, aux-1, 1);
                else if(aux2 < 0)
                    insert(1, 0, n-1, aux-1, -1);
                else
                    insert(1, 0, n-1, aux-1, 0);
            }
            else{
                ans = find(1, 0, n-1, aux-1, aux2-1);
                if(ans > 0) cout << '+';
                else if(ans < 0) cout << '-';
                else cout << 0;
            }
            cin.get();
        }
        cout << "\n";
    }
}
