//TOUGH PROBLEM, ONLY SKELETON IS WRITTEN
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
long int mat[501][501];
long int n, m, q, aux, aux2, score, cur;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i=0; i<n; i++){
        cur = score = 0;
        for(int j=1; j<=m; j++){
            cin >> aux;
            mat[i][j] = aux;
            if(aux) cur++;
            else cur = 0;
            if(cur > score) score = cur;
        }
        mat[i][0] = score;
    }
    for(int i=0; i<q; i++){
        cur = score = 0;
        cin >> aux >> aux2;
        aux--;
        if(mat[aux][aux2]){
            mat[aux][aux2] = 0;
            for(int j = 1; j<=m; j++){
                if(mat[aux][j]) cur++;
                else cur = 0;
                if(cur > score) score = cur;
            }
            mat[aux][0] = score;
        }
        else{
            mat[aux][aux2] = 1;
            for(int j = 1; j<=m; j++){
                if(mat[aux][j]) cur++;
                else cur = 0;
                if(cur > score) score = cur;
            }
            mat[aux][0] = score;
        }
        score = 0;
        for(int j = 0; j<n; j++){
            cur = mat[j][0];
            if(cur>score) score = cur;
        }
        cout << score << "\n";
    }
}
