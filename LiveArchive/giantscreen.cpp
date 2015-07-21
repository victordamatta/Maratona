#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
/*
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define MOD 1000000007
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    ll rh, rv, sh, sv;
    while(cin.peek()!=EOF){
        cin >> rh >> rv >> sh >> sv;
        ll n, rhi, rvi, shi, svi, pi;
        ll vmany, hmany, cost=LLONG_MAX;
        cin >> n;
        f(n, i){
            cin >> rhi >> rvi >> shi >> svi >> pi;
            vmany = hmany = 0;
            hmany = max(hmany, (rh+rhi-1)/rhi);
            vmany = max(vmany, (rv+rvi-1)/rvi);
            hmany = max(hmany, (sh+shi-1)/shi);
            vmany = max(vmany, (sv+svi-1)/svi);
            cost = min(cost, pi*hmany*vmany);
            vmany = hmany = 0;
            hmany = max(hmany, (rh+rvi-1)/rvi);
            vmany = max(vmany, (rv+rhi-1)/rhi);
            hmany = max(hmany, (sh+svi-1)/svi);
            vmany = max(vmany, (sv+shi-1)/shi);
            cost = min(cost, pi*hmany*vmany);
        }
        cout << cost << "\n";
        cin.get();
    }
}
