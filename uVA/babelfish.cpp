#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    string a, b;
    map<string, string> m;
    while(cin.peek()!='\n'){
        cin >> a >> b;
        m[b] = a;
        cin.get();
    }
    while(cin.peek()!=EOF){
        cin >> a;
        if(m.find(a) != m.end()) cout << m[a] << "\n";
        else cout << "eh\n";
        cin.get();
    }
}
