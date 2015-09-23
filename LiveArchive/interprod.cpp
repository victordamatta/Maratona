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

int bit[100007][5], in[100007], n, k, a, b;

int query (int k) {
    if (k == 0) return 1;
    int prod = 1;
    for (int i = k; i>0; i -= i&-i)
        prod *= bit[i][1];
    return prod;
}

int query2 (int k) {
    if (k == 0) return 0;
    int sum = 0;
    for (int i = k; i>0; i -= i&-i)
        sum += bit[i][2];
    return sum;
}

void update (int k, int val, int flag) {
    for (int i = k; i <= n; i += i&-i) {
        if (val != 0) {
            bit[i][1] *= val/abs(val);
            if (flag)
                bit[i][2]--;
        }
        else
            if (!flag)
                bit[i][2]++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n >> k){
        for (int i = 1; i<=n; i++) {
            bit[i][1] = 1;
            bit[i][2] = 0;
        }
        bit[0][1] = 1;
        bit[0][2] = 0;
        for (int i = 1; i<=n; i++){
            cin >> in[i];
            update (i, in[i], 0);
        }
        for (int i = 0; i<k; i++){
            char c;
            cin >> c >> a >> b;
            if (c == 'C') {
                int aux2 = in[a] == 0;
                if (b == 0 && !aux2){
                    update (a, b, aux2);
                    in[a] = 0;
                }
                else if (b!=0 && aux2){
                    update (a, b, aux2);
                    in[a] = 1;
                }
                else if (b/abs(b) != in[a]/abs(in[a])) {
                    update (a, -1, aux2);
                    in[a] *= -1;
                }
            }
            else{
                int aux = query (b)/query (a-1);
                if (aux > 0 && query2(b) == query2(a-1)) cout << "+";
                else if (query2(b) == query2(a-1)) cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
    }
}
