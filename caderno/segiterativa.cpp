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
