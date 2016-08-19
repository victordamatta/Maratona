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
