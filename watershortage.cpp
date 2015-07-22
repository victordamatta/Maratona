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
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

struct box{
    float s;
    float e;
    float c;
} boxs[10007];

bool comp(box a, box b){
    if(a.s != b.s){
        return (a.s < b.s);
    }
    return (a.e < b.e);
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        float v, aux, ans;
        cin >> n;
        f(n, i){
            cin >> boxs[i].s;
            cin >> boxs[i].e;
            boxs[i].e += boxs[i].s;
            cin >> aux;
            cin >> boxs[i].c;
            boxs[i].c *= aux;
        }
        cin >> v;
        sort(boxs, boxs+n, comp);
        f(n, i){
            if(i!=n-1){
                if(boxs[i+1].s >= boxs[i].e){
                    aux = boxs[i].c*(boxs[i].e-boxs[i].s);
                    if(v <= aux){
                        ans = v/boxs[i].c + boxs[i].s;
                        break;
                    }
                    else{
                        v -= aux;
                    }
                }
                else if(boxs[i+1].s == boxs[i].s){
                    boxs[i].c += boxs[i+1].c;
                    boxs[i+1].s = boxs[i].e;
                    i--;
                }
                else{
                    aux = boxs[i].c*(boxs[i+1].s-boxs[i].s);
                    if(v <= aux){
                        ans = v/boxs[i].c + boxs[i].s;
                        break;
                    }
                    else{
                        v -= aux;
                        boxs[i].c += boxs[i+1].c;
                        boxs[i].s = boxs[i+1].s;
                        boxs[i+1].s = boxs[i].e;
                        i--;
                    }
                }
            }
            else{
                aux = boxs[i].c*(boxs[i].e-boxs[i].s);
                if(v <= aux){
                    ans = v/boxs[i].c + boxs[i].s;
                    break;
                }
                else{
                    ans = -1;
                }
            }
        }
        if(ans==-1)
            cout << "OVERFLOW\n";
        else
            cout << fixed << setprecision(2) << ans << "\n";
    }
}
