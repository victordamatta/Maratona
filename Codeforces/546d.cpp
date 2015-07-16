#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, a, b, ans, cont, t;
set<int> primes;
vector<bool> numbers(5010, true);

int main(){
    std::ios::sync_with_stdio(false);
    primes.insert(2);
    for(int i=3; i<5010; i+=2){
        primes.insert(i);
    }
    for(int i = 2; i<5000; i++){
        if(numbers[i]){
            for(int j = i*i; j<5000; j+=i){
                numbers[j] = false;
                primes.erase(j);
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        ans = 0;
        cont = a;
        while(a>b){
            set<int>::iterator it = primes.begin();
            int aux = sqrt(cont)+1;
            while(cont>1){
                if((*it)>aux){
                    ans++;
                    break;
                }
                if(cont%(*it)==0){
                    cont/=(*it);
                    ans++;
                }
                else{
                    it++;
                }
            }
            a--;
            cont = a;
        }
        cout << ans << "\n";
    }
}
