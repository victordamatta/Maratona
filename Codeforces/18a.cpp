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
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int x[3], y[3];

int isright () {
    if(x[1] == x[0] && y[1] == y[0]) return 0;
    if(x[1] == x[2] && y[1] == y[2]) return 0;
    if(x[2] == x[0] && y[2] == y[0]) return 0;
    if((x[1] - x[0]) * (x[2] - x[0]) + (y[1] - y[0]) * (y[2] - y[0]) == 0){
        return 1;
    }
    if((x[0] - x[1]) * (x[2] - x[1]) + (y[0] - y[1]) * (y[2] - y[1]) == 0){
        return 1;
    }
    if((x[1] - x[2]) * (x[0] - x[2]) + (y[1] - y[2]) * (y[0] - y[2]) == 0){
        return 1;
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    if (isright()) cout << "RIGHT\n";
    else{
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        f(3, i){
            f(4, j){
                x[i] += dx[j];
                y[i] += dy[j];
                if(isright()){
                    cout << "ALMOST\n";
                    return 0;
                }
                x[i] -= dx[j];
                y[i] -= dy[j];
            }
        }
        cout << "NEITHER\n";
    }
}
