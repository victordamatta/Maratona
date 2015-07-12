#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, cont, maxi;
int coll[101][101], gc[101];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    fill(gc, gc+101, 1);
    cont = maxi = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> coll[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(coll[i][j]==1) gc[i] = 0;
            else if(coll[i][j]==2) gc[j] = 0;
            else if(coll[i][j]==3){
                gc[i] = 0;
                gc[j] = 0;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        if(gc[i]){
            cont++;
            maxi = max(maxi, i);
        }
    }
    cout << cont << "\n";
    for(int i = 1; i<=n; i++){
        if(gc[i]){
            if(i<maxi)
                cout << i << " ";
            else
                cout << i << "\n";
        }
    }
}
