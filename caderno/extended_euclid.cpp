//TEMPLATE
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
const int MOD = 1000000007;
const int OO = 1000000000;

int main(){
    std::ios::sync_with_stdio(false);
}

//EUCLIDES ESTENDIDO
//O valor retornado eh gcd(a,b) = ax + by
ll gcd_extended(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0, y = 1; return b; }
    ll xx, yy, d = gcd_extended(b%a, a, xx, yy);
    x = yy-(b/a)*xx, y=xx;
    if (d < 0) {d = -d; x = -x; y = -y; }
    return d;
}

//SEG RECURSIVA
int tree[500000], node, t, n, q, a, b, aux, cont=1;

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

	tree[node] = min(tree[2*node], tree[2*node+1]);
}

int tmin(int node, int ini, int fim, int l, int r){
	if(ini>=l && fim<=r) return tree[node];
	if(r<ini || l>fim) return INT_MAX;
	int mid = ini + (fim-ini)/2;
	return min(tmin(2*node, ini, mid, l, r), tmin(2*node+1, mid+1, fim, l, r));
}

int main(){
	scanf("%d", &t);
	while(t--){
		printf("Scenario #%d:\n", cont);
		cont++;
		scanf("%d%d", &n, &q);
		for(int i=0; i<n; i++){
			scanf("%d", &aux);
			insert(1, 0, n-1, i, aux);
		}

		while(q--){
			scanf("%d%d", &a, &b);
			a--;
			b--;
			printf("%d\n", tmin(1, 0, n-1, a, b));
		}
        cout << "\n";
	}
}

//SEG ITERATIVA
const int N = 200;
int tree[2*N];
int n;

void build() {
    for(int i = n-1; i > 0; i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
}

int query(int l, int r) {
    int ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) ret = max(ret, tree[l++]);
        if(r&1) ret = max(ret, tree[--r]);
    }
    return ret;
}

int main () {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",tree+i+n);
    build();
    while(1) {
        int a, b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(a,b+1));
    }
}
