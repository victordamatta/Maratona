#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<string, string> ms;
    string a, b;
    char ca[15], cb[15];
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%s %s", ca, cb);
        a = ca;
        b = cb;
        ms[a] = a.length() <= b.length() ? a : b;
    }
    for(int i = 0; i<n; i++){
        scanf("%s ", ca);
        a = ca;
        cout << ms[a];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}
