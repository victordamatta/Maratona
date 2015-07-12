#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
vector<long int> v, sv;
vector<long int>::iterator it, mit;
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
    sv = v;
    sort(all(sv));
    it = sv.begin();
    mit = v.begin()+mini;
    if(mini==0 && *mit==*(v.end()-1)){
        temp = 2;
        mini = v.size()-1;
        while(*mit == *(v.end()-temp)){
            mini--;
            temp++;
            if(temp>v.size())
                break;
        }
        mit = v.begin()+mini;
    }
    ok = 1;
    while(it!=sv.end()){
        if(*it!=*mit){
            cout << "-1\n";
            ok = 0;
            break;
        }
        it++;
        mit++;
        if(mit==v.end())
            mit = v.begin();
    }
    if(ok)
        if(mini==0)
            cout << "0\n";
        else
            cout << v.size()-mini << "\n";
}
