#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t, d, pck[54], topeat, cont, counter, tep, time;

    scanf("%d", &t);
    for(int x = 0; x<t; x++){
        topeat = 1;
        cont = 1;
        counter = 1;
        time = 0;
        scanf("%d", &d);
        for(int i = 0; i<d; i++)
            scanf("%d ", &pck[i]);
        sort(pck, pck+d);

        while(cont==1){
            if(pck[d-1-counter]==pck[d-1]){
                topeat++;
                counter++;
            } else { 
                cont = 0;
            }
        }
        tep = pck[d-1];
        if(tep%2==0){
            while(tep>topeat+tep/2){
                if(tep%2==0){
                    time++;
                    for(int j = 0; j<topeat; j++){
                        pck[d-1-j] /= 2;
                        pck[d+j] = pck[d-1-j];
                    }
                    d = d+topeat;
                    sort(pck, pck+d);
                    tep = pck[d-1];
                    topeat = 1;
                    counter = 1;
                    cont = 1;
                    while(cont==1){
                        if(pck[d-1-counter]==pck[d-1]){
                            topeat++;
                            counter++;
                        } else { 
                            cont = 0;
                        }
                    }
                }
            }
        }
        time += tep;
        printf("Case #%d: %d\n", x+1, time);
    }
}
