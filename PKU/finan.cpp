#include <cstdio>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    float tmp, avg=0;
    for(int i = 0; i<12; i++){
        scanf("%f", &tmp);
        avg += tmp;
    }
    printf("$%.2f\n", avg/12);
}
