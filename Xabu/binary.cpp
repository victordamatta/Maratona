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
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int ar[300007];

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    FILE * in = fopen ("binary.in", "r");
    FILE * out = fopen ("binary.out", "w");
    in >> n;
    int seek = n;
    bool easy = false, found = false;
    f (n, i) {
        int aux;
        in >> aux;
        if (!easy) {
            if (aux != seek) {
                ar[aux] = 0;
                easy = true;
            }
            else {
                ar[aux] = 0;
                seek--;
            }
        }
        else {
            if (found) ar[aux] = 1;
            else {
                if (aux != seek) ar[aux] = 0;
                else {
                    found = true;
                    ar[aux] = 1;
                }
            }
        }
    }
    f (n, i) out << ar[i+1];
    out << endl;
}
