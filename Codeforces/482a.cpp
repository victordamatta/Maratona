#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 10007
#define OO INT_MAX
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    int n, k, alt = 1, mini, maxi, cur;
    char last = '-';
    cin >> n >> k;
    cout << "1";
    cur = 1;
    maxi = n;
    n--;
    k--;
    mini = 2;
    while(n--){
        if(alt && k){
            cout << " " << maxi;
            cur = maxi;
            maxi--;
            alt = 0;
            k--;
            last = '+';
        }
        else if(k){
            cout << " " << mini;
            cur = mini;
            mini++;
            alt = 1;
            k--;
            last = '-';
        }
        else{
            if(last=='+'){
                cur--;
                cout << " " << cur;
            }
            else{
                cur++;
                cout << " " << cur;
            }
        }
    }
    cout << endl;
}
