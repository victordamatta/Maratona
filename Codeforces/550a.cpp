#include <iostream>
#include <string>
#include <vector>
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

string s;
int i, x, y;
vector< pair<int, int> > s1, s2;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> s;
    string::iterator it = s.begin();
    i=0;
    while(it!=s.end()){
        if(*it == 'A' && it!=s.end()-1){
            x = i;
            if(*(it+1)=='B'){
                y = i+1;
                s1.push_back(make_pair(x, y));
            }
        }
        if(*it == 'B' && it!=s.end()-1){
            x = i;
            if(*(it+1)=='A'){
                y = i+1;
                s2.push_back(make_pair(x, y));
            }
        }
        it++;
        i++;
    }
    if(s1.size()>1 && s2.size()>1)
        cout << "YES\n";
    else{
        vector< pair<int, int> >::iterator it1 = s1.begin();
        vector< pair<int, int> >::iterator it2 = s2.begin();
        i = 1;
        while(it1!=s1.end()){
            while(it2!=s2.end()){
                if(it1->first!=it2->first && it1->second!=it2->first && it1->first!=it2->second && it1->second!=it2->second){
                    cout << "YES\n";
                    i = 0;
                    break;
                }
                it2++;
            }
            it2 = s2.begin();
            it1++;
        }
        if(i)
            cout << "NO\n";
    }
    return 0;
}
