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
int mat[1007][1007];

char rotate (char c) {
    if (c == '-') {
        return '|';
    }
    else if (c == '|') {
        return '-';
    }
    else if (c == '^') {
        return '>';
    }
    else if (c == '>') {
        return 'v';
    }
    else if (c == 'v') {
        return '<';
    }
    else if (c == '<') {
        return '^';
    }
    else if (c == 'L') {
        return 'U';
    }
    else if (c == 'U') {
        return 'R';
    }
    else if (c == 'R') {
        return 'D';
    }
    else if (c == 'D') {
        return 'L';
    }
    else return c;
}

bool access (char c, char d) {
    
}

int main(){
    std::ios::sync_with_stdio(false);
}
