#include <bits/stdc++.h>
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

int main(){
    std::ios::sync_with_stdio(false);
    int n, d, l, sum;
    cin >> n >> d >> l;
    vi v(101);
    sum = 0;
    f(n){
        if(i%2==0){
            v[i] = l;
            sum += l;
        }
        else{
            v[i] = 1;
            sum--;
        }
    }
    if(d>sum){
        cout << "-1\n";
        return 0;
    }
    f(n){
        if(sum-d >= l-1){
            if(i%2==0){
                v[i] = 1;
                sum -= l-1;
            }
            else{
                v[i] = l;
                sum -= l-1;
            }
        }
        else{
            if(i%2==0){
                v[i] -= sum-d;
                sum = d;
            }
            else{
                v[i] += sum-d;
                sum = d;
            }
        }
    }
    if(sum != d) cout << "-1\n";
    else{
        cout << v[0];
        f(n-1){
            cout << " " << v[i+1];
        }
        cout << "\n";
    }
}
