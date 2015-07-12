#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

string s, t;
long int p, n;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> s >> t;
    n = s.size();
    string::iterator it1 = s.begin(), it2 = t.begin();
    p = 0;
    while(it1!=s.end()){
        if(*it1!=*it2) p++;
        it1++;
        it2++;
    }
    if(p>0){
        if(p%2==1){
            cout << "impossible\n";
            while(it1!=s.end()){
            }
        }
        else{
            it1 = s.begin();
            it2 = t.begin();
            p = 0;
            while(it1!=s.end()){
                if(*it1==*it2)
                    cout << *it1;
                else if(p%2==0){
                    cout << *it1;
                    p++;
                }
                else{
                    cout << *it2;
                    p++;
                }
                it1++;
                it2++;
            }
            cout << "\n";
        }
    }
    else{
        it1 = s.begin();
        if(*it1=='0'){
            cout << "1";
        }
        else
            cout << "0";
        it1++;
        while(it1!=s.end()){
            cout << *it1;
            it1++;
        }
        cout << "\n";
    }
}
