#include <iostream>
#include <string>
using namespace std;

long int elev(int x){
    if(x==0) return 1;
    else return 10*elev(x-1);
}

int main(){
    std::ios::sync_with_stdio(false);
    string a, x, y;
    int size, ans;
    while(cin >> a, a!="0"){
        ans = 0;
        size = a.length()/2;
        x = a.substr(0, size);
        if(a.length()%2==0){
            y = a.substr(size, size);
            for(int i=0; i<size; i++){
                if(x[i]>y[size-1-i]){
                    ans += ((x[i]-'0') - (y[size-1-i]-'0'))*elev(i);
                }
                else if(x[i]<y[size-1-i]){
                    ans += (10+(x[i]-'0') - (y[size-1-i]-'0'))*elev(i);
                    if(i<size-1){
                        y[size-2-i] = y[size-2-i]+1;
                    }
                    else
                        ans += elev(size-1);
                }
            }
        }
        else{
            y = a.substr(size+1, size);
            for(int i=0; i<size; i++){
                if(x[i]>y[size-1-i]){
                    ans += ((x[i]-'0') - (y[size-1-i]-'0'))*elev(i);
                }
                else if(x[i]<y[size-1-i]){
                    ans += (10+(x[i]-'0') - (y[size-1-i]-'0'))*elev(i);
                    if(i<size-1)
                        y[size-2-i] = y[size-2-i]+1;
                }
            }
        }
        cout << ans << "\n";

    }
}
