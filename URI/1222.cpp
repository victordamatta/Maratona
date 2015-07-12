#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, l, c, counter=0, uper=0, templ, tempc, pages=0;
    string str;
    while(scanf(" %d %d %d ", &n, &l, &c)!=EOF){
        //printf("%d %d %d\n", n, l, c);
        getline(cin, str);
        //cout << str<< endl;
        tempc = c;
        templ = l-1;
        uper = 0;
        counter = 0;
        pages = 1;
        while(uper<str.length()){
            counter = 0;
            while(str[uper]!=' ' && uper<str.length()){
                //cout << str[uper];
                counter++;
                uper++;
            }
            uper++;
            if(counter+1<=tempc){
                tempc-=counter+1;
            } else if (counter==tempc){
                tempc-=counter;
            } else {
                tempc = c - (counter+1);
                if (templ>0){
                    templ--;
                    //cout << templ <<endl;
                } else {
                    templ = l-1;
                    //cout << templ <<endl;
                    pages++;
                }
            }
        }
        //cout << templ <<endl;
        /*if (tempc<c){
            if(templ==0){
                pages++;
            }
        }*/
        printf("%d\n", pages);
    }

    return 0;
}
