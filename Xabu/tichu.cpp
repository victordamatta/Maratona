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
#define pi pair<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
typedef pair<char, char> p;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int t;
p hand[20];
char order[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int answer[20][20], inv[20];

char next (char x) {
    for (int i = 0; i<12; i++){
        if (order[i] == x) return order[i+1];
    }
    return 'X';
}

bool ord (p a, p b) {
    for (int i = 0; i<13; i++) {
        if (order[i] == a.first) return 1;
        if (order[i] == b.second) return 0;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ms (inv, 0);
        f(13, i) {
            cin >> hand[i].first >> hand[i].second;
        }
        sort (hand, hand+13, ord);

        char aux = hand[0];
        int ds=0, ts=0, qs=0, stri=0, strf=0, i=1;
        int handb = 0, ans = 0, ns = 0;
        while (i < 13) {
            if (hand[i].first == aux) {
                i++;
                continue;
            }
            if (hand[i].first == next(aux)) {
                strf++;
            }
            else {
                if (strf - stri >= 5) {
                    for (int j = 0; j<=strf-stri; j++) {
                        answer[ns][j] = stri + j;
                        inv[stri+j] = 1;
                    }
                    ns++;
                }
                stri = strf = i;
            }
            aux = hand[i].first;
        }
        aux = hand[0].first;
        i = 1;
        while (i < 13) {
            if (inv[i]) {
                i++;
                continue;
            }
            if (i<12 && hand[i].first == aux) {
                if (i < 11 && hand[i+1].first == aux) {
                    if (i < 10 && hand[i+2].first == aux) {
                        qs++;
                        i += 3;
                    }
                    else {
                        ts++;
                        i += 2;
                    }
                }
                else {
                    ds++;
                    i++; 
                }
            }
            aux = hand[i].first;
        }
        int halp = 13;
        //Print all the combinations
    }
}
