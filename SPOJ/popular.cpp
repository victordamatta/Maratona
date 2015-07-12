#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
int maxi, aux, n;
vector<int> votos(100, 0);
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    while(n!=0){
        maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> aux;
                if(aux)
                    votos[j]++;
                if(votos[j]>maxi) maxi = votos[j];
            }
        }
        cout << maxi << "\n";
        fill(votos.begin(), votos.end(), 0);
        cin >> n;
    }
}
