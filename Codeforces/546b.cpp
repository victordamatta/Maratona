#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

set<int> s;
int n, aux;
long int ans;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    ans = 0;
    for(int i = 0; i<n; i++){
        cin >> aux;
        if(s.find(aux)==s.end()){
            s.insert(aux);
        }
        else{
            do{
                ans++;
                aux++;
            }while(s.find(aux)!=s.end());
            s.insert(aux);
        }
    }
    cout << ans << "\n";
}
