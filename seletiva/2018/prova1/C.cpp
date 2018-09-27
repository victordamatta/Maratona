
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

ll t, n, r, k;
ll start[12];
ll mat[12][12];
ll aux[12][12];

void identify(ll m[][12], ll sz) {
    for(ll i = 0; i < sz; i++)
        for(ll j = 0; j < sz; j++)
            m[i][j] = i == j;
}

void apply(ll m[][12], ll v[], ll sz) {
    ll v2[12];
    for(ll i = 0; i < sz; i++) v2[i] = v[i];

    for(ll i = 0; i < sz; i++) {
        v[i] = 0;
        for(ll j = 0; j < sz; j++) {
            v[i] += mod(m[i][j]*v2[j]);
            v[i] = mod(v[i]);
        }
    }
}

void mult(ll m1[][12], ll m2[][12], ll sz) {
    ll res[12][12];

    for(ll i = 0; i < sz; i++) {
        for(ll j = 0; j < sz; j++) {
            res[i][j] = 0;
            for(ll k = 0; k < sz; k++) {
                res[i][j] += mod(m1[i][k]*m2[k][j]);
                res[i][j] = mod(res[i][j]);
            }
        }
    }

    for(ll i = 0; i < sz; i++)
        for(ll j = 0; j < sz; j++)
            m1[i][j] = res[i][j];
}

void fexp(ll c[][12], ll op[][12], ll n, ll sz) {
    if(n == 0) return;

    if(n%2 == 0) return mult(op, op, sz), fexp(c, op, n/2, sz);
    else return mult(c, op, sz), fexp(c, op, n-1, sz);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> r >> k;
        for(ll i = 0; i < r; i++) {
            cin >> start[i];
        }
        for(ll i = 0; i < r-1; i++) {
            for(ll j = 0; j < r; j++) {
                aux[i][j] = i == j-1;
            }
        }
        for(ll i = 0; i < r; i++) {
            cin >> aux[r-1][r-i-1];
        }
        identify(mat, r);

        ll count = 0;
        start[r] = 0;
        for(ll i = k-1; i < r; i += k) {
            start[r] += start[i];
            start[r] = mod(start[r]);
            count++;
            if(count == n) goto end;
        }
        if(r % k != 0) {
            for(ll j = r; j % k != 0; j++) apply(aux, start, r);
            start[r] += start[r-1];
            start[r] = mod(start[r]);
            count++;
            if(count == n) goto end;
        }

        fexp(mat, aux, k, r);
        for(ll i = 0; i < r; i++) mat[i][r] = 0;
        for(ll i = 0; i < r; i++) mat[r][i] = mat[r-1][i];
        mat[r][r] = 1;

        identify(aux, r+1);
        fexp(aux, mat, n-count, r+1);
        apply(aux, start, r+1);
end:
        cout << start[r] << endl;
    }
}

// How it should have been done
/*
struct Matrix {
    int d[12][12];
    int size;

    Matrix(int size) : size(size) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                d[i][j] = i == j;
            }
        }
    }

    Matrix operator*(const Matrix& b) {
        Matrix ans(size);
        
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                ans.d[i][j] = 0;
                for(int k = 0; k < size; k++) {
                    ans.d[i][j] = (ans.d[i][j] + (d[i][k]*b.d[k][j]) % MOD) % MOD;
                }
            }
        }

        return ans;
    }

    vector<int> operator*(const vector<int>& v) {
        vector<int> ans(size);

        for(int i = 0; i < size; i++) {
            ans[i] = 0;
            for(int j = 0; j < size; j++) {
                ans[i] = (ans[i] + (d[i][j]*v[j]) % MOD) % MOD;
            }
        }

        return ans;
    }
};

Matrix fexp(Matrix m, int exp) {
    if(exp == 0) return Matrix(m.size);
    else if (exp % 2 == 0) return fexp(m*m, exp/2);
    else return m * fexp(m, exp - 1);
}
*/
