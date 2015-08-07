#include <bits/stdc++.h>
using namespace std;

set<int> m;
int need[107];
int n;
long long int prev, ans;
int v;
char s;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    memset(need, 0, sizeof need);
    prev = ans = 0;
    for(int i=1; i<=n; i++){
        cin >> s >> v;
        cin.get();
        if(s == '+'){
            need[i]++;
            m.insert(v);
        }
        else{
            if(m.find(v)==m.end()){
                need[i]--;
                for(int j=0; j<=i-1; j++){
                    need[j]++;
                    if(need[j] > ans) ans = need[j];
                }
            }
            else{
                need[i]--;
                m.erase(v);
            }
        }
        need[i]+=need[i-1];
        if(need[i] > ans) ans = need[i];
    }
    cout << ans << "\n";
    return 0;
}
