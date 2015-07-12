#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
int n, k1, k2, aux1, aux2, cont, rep;
queue<int> q1, q2;
set< queue<int> > s;
vector<int> v;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> k1;
    for(int i=0; i<k1; i++){
        cin >> aux1;
        q1.push(aux1);
    }
    cin >> k2;
    for(int i=0; i<k2; i++){
        cin >> aux2;
        q2.push(aux2);
    }
    cont = 0;
    s.insert(q1);
    rep = 0;
    do{
        aux1 = q1.front();
        aux2 = q2.front();
        q1.pop();
        q2.pop();
        if(aux1>aux2){
            q1.push(aux2);
            q1.push(aux1);
        }
        else{
            q2.push(aux1);
            q2.push(aux2);
        }
        if(s.find(q1)!=s.end()){
            v.push_back(1);
        }
        if(v.size()==100){
            rep = 1;
            break;
        }
        s.insert(q1);
        cont++;
    }while(!q1.empty() && !q2.empty());
    if(rep)
        cout << "-1\n";
    else if(q1.empty())
        cout << cont << " 2\n";
    else
        cout << cont << " 1\n";
}
