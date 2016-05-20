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
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int tree[400000];

int GCD (int a, int b) {
    if (a < b) swap (a, b);
    if (b == -1 || b == 0) return a;
    return GCD (b, a % b);
}

void insert(int node, int ini, int fim, int ind, int value){
	int mid = ini + (fim-ini)/2;
	if(ini==fim) {
		tree[node] = value;
		return;
	}
	if(ind<=mid)
		insert(2*node, ini, mid, ind, value);
	else if(ind>mid)
		insert(2*node+1, mid+1, fim, ind, value);

	tree[node] = GCD(tree[2*node], tree[2*node+1]);
}

int tmin(int node, int ini, int fim, int l, int r){
	if(ini>=l && fim<=r) return -1;
	if(r<ini || l>fim) return tree[node];
	int mid = ini + (fim-ini)/2;
	return GCD(tmin(2*node, ini, mid, l, r), tmin(2*node+1, mid+1, fim, l, r));
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    f (n, i) {
        int aux;
        cin >> aux;
        insert (1, 0, n-1, i, aux);
    }

    int ans = 0;
    f (n, i) {
        for (int j = i; j < n; j++) {
            if (j - i + 1 >= n-1) continue;
            ans += tmin (1, 0, n-1, i, j);
        }
    }
    cout << ans << endl;
}
