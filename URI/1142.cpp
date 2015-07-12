
#include <stdio.h>

using namespace std;

int main(){
    int n, x=1, y=2, z=3;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        printf("%d %d %d PUM\n", x, y, z);
        x+=4;
        y+=4;
        z+=4;
    }

    return 0;
}
