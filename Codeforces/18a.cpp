#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

float x1, y1, x2, y2, x3, y3, m1, m2;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(((y1-y2)/(x1-x2))*((y1-y3)/(x1-x3))==-1)
        cout << "RIGHT\n";
    else if(((y2-y3)/(x2-x3))*((y2-y1)/(x2-x1))==-1)
        cout << "RIGHT\n";
    else if(((y3-y2)/(x3-x2))*((y3-y1)/(x3-x1))==-1)
        cout << "RIGHT\n";
    else if(((y1+1-y2)/(x1-x2))*((y1+1-y3)/(x1-x3))==-1)
        cout << "ALMOST\n";
    else if(((y2-y3)/(x2-x3))*((y2-y1+1)/(x2-x1))==-1)
        cout << "ALMOST\n";
    else if(((y3-y2)/(x3-x2))*((y3-y1+1)/(x3-x1))==-1)
        cout << "ALMOST\n";
    else if(((y1-1-y2)/(x1-x2))*((y1-1-y3)/(x1-x3))==-1)
        cout << "ALMOST\n";
    else if(((y2-y3)/(x2-x3))*((y2-y1-1)/(x2-x1))==-1)
        cout << "ALMOST\n";
    else if(((y3-y2)/(x3-x2))*((y3-y1-1)/(x3-x1))==-1)
        cout << "ALMOST\n";
    else if(((y1-y2+1)/(x1-x2))*((y1-y3)/(x1-x3))==-1)
        cout << "ALMOST\n";
    else if(((y2+1-y3)/(x2-x3))*((y2+1-y1)/(x2-x1))==-1)
        cout << "ALMOST\n";
    else if(((y3-y2+1)/(x3-x2))*((y3-y1)/(x3-x1))==-1)
        cout << "ALMOST\n";
    else if(((y1-y2-1)/(x1-x2))*((y1-y3)/(x1-x3))==-1)
        cout << "ALMOST\n";
    else if(((y2-1-y3)/(x2-x3))*((y2-1-y1)/(x2-x1))==-1)
        cout << "ALMOST\n";
    else if(((y3-y2-1)/(x3-x2))*((y3-y1)/(x3-x1))==-1)
        cout << "ALMOST\n";
}
