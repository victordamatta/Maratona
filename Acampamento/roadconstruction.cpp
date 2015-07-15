#include <iostream>
#include <set>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, m, x, y;
set<int> s1, s2;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        s1.insert(i);
        s2.insert(i);
    }
    while(m--){
        cin >> x >> y;
        if(s1.find(x)!=s1.end())
            s1.erase(x);
        if(s1.find(y)!=s1.end())
            s1.erase(y);
    }
    set<int>::iterator it, it2;
    it = s1.begin();
    s2.erase(*it);
    it2 = s2.begin();
    cout << --n << "\n";
    while(n--){
        cout << *it << " " << *it2 << "\n";
        it2++;
    }
}
