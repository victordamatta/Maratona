#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

string in;
map<string, long int> m;
long int n;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    while(n--){
        cin >> in;
        if(m.find(in)==m.end()){
            m[in] = 1;
            cout << "OK\n";
        }
        else{
            cout << in << m[in] << "\n";
            m[in]++;
        }
    }
    
}
