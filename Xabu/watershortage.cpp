#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

struct box{
    float s;
    float e;
    float c;
};

bool comp(box a, box b){
    if(a.s != b.s){
        return a.s < b.s;
    }
    return a.e < b.e;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        vector<box> v;
        int n;
        cin >> n;
        f(n, i){
            float aux, aux2;
            box tmp;
            cin >> tmp.s;
            cin >> aux;
            tmp.e = tmp.s + aux;
            cin >> aux >> aux2;
            tmp.c = aux*aux2;
            v.pb(tmp);
        }
        float vol, ans, aux;
        cin >> vol;
        sort(all(v), comp);
        int x = v.size()-1;
        f(x, i){
            if(v[i+1].s >= v[i].e) continue;
            //box separation wrong
        }
        sort(all(v), comp);
        f(v.size(), i){
            cout << v[i].s << " " << v[i].e << " " << v[i].c << endl;
            if(i!=v.size()-1){
                aux = v[i].c*(v[i].e-v[i].s);
                if(vol <= aux){
                    ans = v[i].s + vol/v[i].c;
                    break;
                }
                else vol -= aux;
            }
            else{
                aux = v[i].c*(v[i].e-v[i].s);
                if(vol <= aux){
                    ans = v[i].s + vol/v[i].c;
                    break;
                }
                else ans = -1;
            }
        }
        if(ans == -1)
            cout << "OVERFLOW\n";
        else
            cout << ans << "\n";
    }
}
