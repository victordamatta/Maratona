#include <iostream>
using namespace std;
int main(){
    for(int i = 12; i<=1000000; i++){
        if(i/2+i/3+i/4<i) cout << i << "\n";
    }
}
