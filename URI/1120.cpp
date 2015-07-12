#include <string>
#include <iostream>

using namespace std;

int main(){
    string d, n;
    do{
        cin >> d >> n;
        if((d.compare("0")==0 && n.compare("0")==0)){/*cout<<endl;*/ break;}
        while(n.find(d)!=string::npos){
            n.erase(n.find(d), 1);
        }
        while(n[0]=='0'){
            n = n.substr(1, n.size());
        }
        if (n.size()==0){
            cout << 0 << endl;
        }else{
            cout << n << endl;
        }
    }while(d.compare("0")!=0 && n.compare("0")!=0);

    return 0;
}
