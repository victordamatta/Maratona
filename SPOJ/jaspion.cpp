#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int t, n, m;
string a, b;
map<string, string> ms;

int main(){
    while(scanf("%ld", &t)!=EOF){
        scanf("%ld%ld", &m, &n);
        for(long int i=0; i<m; i++){
            getline(cin, a);
            getline(cin, b);
            cout << a << "\n" << b << "\n";
            ms[a] = b;
        }
        for(long int i=0; i<n; i++){
            getline(cin, a);
            b = "";
            string::iterator it = a.begin();
            while(*it!='\n'){
                while(*it!=' '){
                    b+=*it;
                    it++;
                }
                if(ms.find(b)!=ms.end())
                    cout << ms[b] << " ";
                else
                    cout << b << " ";
                it++;
            }
            cout << "\n";
        }
    }
}
