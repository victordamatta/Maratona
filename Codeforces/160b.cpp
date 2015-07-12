#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
num n, t;
char aux;
vector<int> v1, v2;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> aux;
        v1.push_back(aux-'0');
    }
    for(int i=0; i<n; i++){
        cin >> aux;
        v2.push_back(aux-'0');
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int>::iterator it1=v1.begin(), it2=v2.begin();
    if(*it1==*it2){
        cout << "NO\n";
    }
    else if(*it1 < *it2){
        it1++;
        it2++;
        while(it1!=v1.end()){
            if(*it1>=*it2){
                cout << "NO\n";
                return 0;
            }
            it1++;
            it2++;
        }
        cout << "YES\n";
        return 0;
    }
    else{
        it1++;
        it2++;
        while(it1!=v1.end()){
            if(*it1<=*it2){
                cout << "NO\n";
                return 0;
            }
            it1++;
            it2++;
        }
        cout << "YES\n";
        return 0;
    }
}
