#include <iostream>
using namespace std;

int main(){
  int t, n, m, d, h;
  cin >> t;
  while(t--){
    cin >> n >> m >> d;
    while(n--){
      cin >> h;
      while(m>0 && h>d){
        h-=d;
        m--;
      }
    }
    if(m==0) cout << "YES\n";
    else cout << "NO\n";
  }
}
