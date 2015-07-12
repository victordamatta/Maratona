#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

map<int, int> m;
int n, p;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> p;
        m[p] = i;
    }
    for(int i = 1; i<=n; i++){
        if(i!=n)
            cout << m[i] << " ";
        else
            cout << m[i] << "\n";
    }
}
