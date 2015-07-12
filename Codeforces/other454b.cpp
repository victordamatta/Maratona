#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
vector<long int> v, nv;
vector<long int>::iterator it;
long int n, temp, mini;
int ok;

int main(){
    cin >> n;
    cin >> temp;
    v.push_back(temp);
    mini = 0;
    for(long int i = 1; i<n; i++){
        cin >> temp;
        v.push_back(temp);
        if(temp < v[mini]){
            mini = i;
        }
    }
    it = v.begin() + mini;
    if(mini==0 && *it==*(v.end()-1)){
        temp = 2;
        mini = v.size()-1;
        while(*it == *(v.end()-temp)){
            mini--;
            temp++;
            if(temp>v.size())
                break;
        }
        it = v.begin()+mini;
    }
    ok = 1;
    temp = v.size();
    while(temp--){
        nv.push_back(*it);
        it++;
        if(it==v.end())
            it = v.begin();
    }
    temp = *nv.begin();
    it = nv.begin()+1;
    while(it!=nv.end()){
        if(*it<temp){
            cout << "-1\n";
            return 0;
        }
        temp = *it;
        it++;
    }
    if(mini!=0)
        cout << v.size() - mini << "\n";
    else
        cout << "0\n";
}
