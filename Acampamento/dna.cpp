#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    int k, max;
    string a, b, c;
    while(cin >> k, k!=0){
        cin >> a >> b;
        string::iterator it1, it2;
        it1 = a.begin();
        max = 0;
        while(it1!=a.end()){
            c = "";
            it2 = b.begin();
            while(it2 != b.end()){
                while(*it2 != *it1 && it2 != b.end()){
                    it2++;
                }
                while(*it1==*it2 && it2 != b.end()){
                    c = c + *it1;
                    it1++;
                    it2++;
                }
            }
            if(c.length()>max) max = c.length();
            cout << c << "\n";
            it1++;    
        }
        cout << max << "\n";
    }
}
