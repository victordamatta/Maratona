#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

char invert(char signal){
    if(signal=='+')
        return '-';
    else
        return '+';
}

string quaternion(string first, string second){
    char stemp, sans, lans;
    str ans;

    if(fist[0]==second[0])
        stemp = '+';
    else 
        stemp = '-';
    
    if(first[1]==1){
        lans = second[1];
        sans = stemp;
    }
    else if(second[1]==1){
        lans = first[1];
        sans = stemp;
    }
    else if(first[1]==second[1]){
        lans = '1';
        sans = invert(stemp);
    }
    else if(first[1]=='i'){
        if(second[1]=='j'){
            lans = 'k';
            sans = stemp;
        }
        else if(second[1]=='k'){
            lans = 'j';
            sans = invert(stemp);
        }
    }
    else if(first[1]=='j'){
        if(second[1]=='i'){
            lans = 'k';
            sans = invert(stemp);
        }
        else if(second[1]=='k'){
            lans = 'i';
            sans = stemp;
        }
    }
    else if(first[1]=='k'){
        if(second[1]=='j'){
            lans = 'i';
            sans = invert(stemp);
        }
        else if(second[1]=='i'){
            lans = 'j';
            sans = stemp;
        }
    }
    ans = snas + lans;
    return ans;
}

int main(){
    int t, l, x, counter = 0;
    char letter;
    string s1, s2;

    scanf("%d", &t);
    for(int a = 0; a<t; a++){
        scanf(" %d %d", &l, &x);
        scanf("%c", &letter);
        s1 = '+' + letter;
        for(int b = 0; b<x; b++){
            for(int c = 1; c<x; c++){
                scanf("%c", &letter);
                if(counter==0){
                    if(s1=="+i"){
                        counter++;
                        s1 = '+' + letter;
                    }
                    else{
                        s2 = '+' + letter;
                        s1 = quaternion(s1, s2);
                    }
                }
                else if(counter==1){
                    if(s1=="+j"){
                        counter++;
                        s1 = '+' + letter;
                    }
                    else{
                        s2 = '+' + letter;
                        s1 = quaternion(s1, s2);
                    }
                }
                else if(counter==2){
                    if(s1=="+k"){
                        counter++;
                        s1 = '+' + letter;
                    }
                    else{
                        s2 = '+' + letter;
                        s1 = quaternion(s1, s2);
                    }
                }
                else if(counter==3){
                    if()
                }
            }
        }
    }
}
