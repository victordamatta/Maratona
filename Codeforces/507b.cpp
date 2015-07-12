#include <bits/stdc++.h>
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long long int r, x, y, a, b, dis;

int main(){
    cin >> r >> x >> y >> a >> b;
    a = a-x;
    b = b-y;
    dis = (long long int)ceil(sqrt(a*a+b*b));
    r *= 2;
    if(dis%r==0)
        cout << dis/r << "\n";
    else 
        cout << dis/r + 1 << "\n";
}
