#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string num;
    int ok = 0, mok = 0;
    cin >> num;
    string::iterator it = num.begin();
    string::iterator mini;
    while(it!=num.end()){
        if((*it-'0')%2==0){
            if(*it < *(num.end()-1)){
                swap(*it, *(num.end()-1));
                ok = 1;
                break;
            }
            mini = it;
            mok = 1;
        }
        it++;
    }
    if(ok)
        cout << num << "\n";
    else if(mok){
        swap(*mini, *(num.end()-1));
        cout << num << "\n";
    }
    else
        cout << "-1\n";
}
