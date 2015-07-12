#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

string s;

int main(){
    std::ios::sync_with_stdio(false);
    string a = "hello";
    cin >> s;
    int pass = 0, i=0;
    string::iterator it = s.begin();
    while(it!=s.end() && pass==0){
        if(*it==a[i] && i==4 && pass==0)
            pass = 1;
        else if(*it==a[i] && pass==0)
            i++;
        it++;
    }
    if(pass)
        cout << "YES\n";
    else
        cout << "NO\n";
}
