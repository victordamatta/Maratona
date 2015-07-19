#include <cstdio>
#include <iostream>
#include <algorithm>
#define all(x) x.begin(), x.end()

using namespace std;
typedef int num;

//REMEMBER TO DECLARE GLOBAL VARIABLES

int t, n, na, nb;

struct event{
    int time;
    int place;
    int type;
} events[1005];

bool comp(event a, event b){
    if(a.time!=b.time) return (a.time < b.time);
    return (a.type < b.type);
}

int main(){
    scanf(" %d", &t);
    for(int ii=1; ii<=t; ii++){
        scanf(" %d %d %d", &n, &na, &nb);
        int aux, aux2;
        for(int i=0; i<2*na; i+=2){
            scanf("%d:%d", &aux, &aux2); 
            events[i].time = 60*aux + aux2;
            events[i].place = 1;
            events[i].type = 1;
            scanf("%d:%d", &aux, &aux2); 
            events[i+1].time = 60*aux + aux2+n;
            events[i+1].place = 0;
            events[i+1].type = 0;
        }
        for(int i=2*na; i<2*(na+nb); i+=2){
            scanf("%d:%d", &aux, &aux2); 
            events[i].time = 60*aux + aux2;
            events[i].place = 0;
            events[i].type = 1;
            scanf("%d:%d", &aux, &aux2); 
            events[i+1].time = 60*aux + aux2+n;
            events[i+1].place = 1;
            events[i+1].type = 0;
        }

        sort(events, events+2*(na+nb), comp);

        int a=0, ea=0, eb=0, b=0;
        for(int i=0; i<2*(na+nb); i++){
            if(events[i].place == 1){
                if(events[i].type == 1){
                    if(ea) ea--;
                    else a++;
                }
                else ea++;
            }
            else{
                if(events[i].type == 1){
                    if(eb) eb--;
                    else b++;
                }
                else eb++;
            }
        }

        cout << "Case #" << ii << ": " << a << ' ' << b << '\n';
    }
}
