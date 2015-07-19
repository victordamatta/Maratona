#include <iostream>
#include <climits>
#include <vector>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 100007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    vi alc(MAX, 0), cost(MAX, 0);
    int n, mcost, aux, costn, costm;
    cin >> n;
    mcost = INT_MAX;
    f(n){
        cin >> aux;
        costm = 0;
        int aux2;
        while(aux >= 1){
            costn = 0;
            aux2 = aux;
            do{
                alc[aux2]++;
                cost[aux2] += costn+costm;
                if(alc[aux2]==n){
                    if(cost[aux2] < mcost){
                        //cout << aux2 << " " << cost[aux2] << "\n";
                        mcost = cost[aux2];
                    }
                } 
                aux2*=2;
                costn++;
            }while(aux2 < MAX);
            if(aux%2==1){
                aux /= 2;
                costm++;
            }
            else{
                while(aux > 0 && aux%2==0){
                    aux /= 2;
                    costm++;
                    alc[aux]++;
                    cost[aux] += costm;
                    if(alc[aux]==n){
                        if(cost[aux] < mcost){
                            //cout << aux2 << " " << cost[aux2] << "\n";
                            mcost = cost[aux];
                        }
                    }
                }
                aux /= 2;
                costm++;
            }
        }
    }
    cout << mcost << "\n";
}
