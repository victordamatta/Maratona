#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    long int val = 0;
    string in;
    char c = 'a';
    int temp, maxi, k;
    map<char, int> m;
    cin >> in;
    cin >> k;
    cin >> maxi;
    m[c] = maxi;
    for(int i = 1; i<26; i++){
        cin >> temp;
        m[c+i] = temp;
        if(temp>maxi)
            maxi = temp;
    }
    string::iterator it = in.begin();
    temp = 1;
    while(it!=in.end()){
        val += m[*it]*temp;
        it++;
        temp++;
    }
    while(k--){
        val += maxi*temp;
        temp++;
    }
    cout << val << "\n";
    return 0;
}
