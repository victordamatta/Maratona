#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    if(n%4==0 || n%7==0 || n%47 == 0 || n%74==0 || n%444==0 || n%447==0 || n%474==0 || n%477==0 || n%744==0 || n%747==0 || n%774==0 || n%777==0)
        cout << "YES\n";
    else cout << "NO\n";
}
