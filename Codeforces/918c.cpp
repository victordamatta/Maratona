
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 5007;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

string s;
bool OK[N][N];

int main(){
    std::ios::sync_with_stdio(false);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            OK[i][j] = false;
        }
    }
    int ans = 0;

    cin >> s;

    int balance, energy;
    for(int l = 0; l < s.size(); l++) {
        balance = energy = 0;
        for(int r = l; r < s.size(); r++) {
            if(s[r] == '(') balance++;
            else if(s[r] == ')') balance--;
            else energy++;

            if(balance + energy < 0) break;
            bool is_even = ((r - l + 1) % 2) == 0;
            if(is_even) OK[l][r] = true;
        }
    }
    for(int r = s.size() - 1; r >= 0; r--) {
        balance = energy = 0;
        for(int l = r; l >= 0; l--) {
            if(s[l] == '(') balance++;
            else if(s[l] == ')') balance--;
            else energy++;

            if(energy - balance < 0) break;
            if(OK[l][r]) ans++;
        }
    }
    cout << ans << endl;
}
