#include <cstdio>
#include <map>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

char tmp, tmp2, mat[300][26];
int main(){
    map<char, int> m;
    int max, aux;
    tmp = 'A';
    for(int i = 0; i<26; i++){
        tmp2 = tmp+i;
        m[(char)tmp2] = 0;
    }
    while(scanf("%c", &tmp)!=EOF){
        if('A'<=tmp && tmp<='Z'){
            m[tmp] = m[tmp] + 1;
            //printf("%c\n", tmp);
            //printf("%d\n", m[tmp]);
        }
    }
    max = 0;
    for(int i=0; i<26; i++){
        mat[299][i] = (char)('A'+i);
        aux = m['A'+i];
        //printf("%d", aux);
        //printf("%c/ %c/ %d \n",tmp, tmp+i, aux);
        if(aux>max) max = aux;
        for(int j=0; j<aux; j++){
            mat[298-j][i] = '*';
            //printf(" %c\n", mat[298-j][i]);
        }
        for(int j=aux; j<297; j++){
            mat[298-j][i] = ' ';
        }
    }
    for(int i=300-max-1; i<300; i++){
        for(int j=0; j<26; j++){
            printf("%c", mat[i][j]);
            if (j<25) printf(" ");
        } 
        printf("\n");
    }
}
