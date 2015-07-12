#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

class Robot{
    public:
        int vertical;
        int horizontal;
        char direction;
        int stickers;

        void walk(char map[101][101], int mapsizev, int mapsizeh){
            if (direction == 'N'){
                if(map[vertical-1][horizontal]!='#' && vertical-1>=0){
                vertical--;}
            } else if (direction == 'S'){
                if(map[vertical+1][horizontal]!='#' && vertical+1<mapsizev){
                vertical++;}
            } else if (direction == 'L'){
                if(map[vertical][horizontal+1]!='#' && horizontal+1<mapsizeh){
                horizontal++;}
            } else {
                if(map[vertical][horizontal-1]!='#' && horizontal-1>=0){
                horizontal--;}
            }
        }
        void changedir(char command){
            if (direction == 'N'){
                if (command=='E'){
                    direction = 'O';
                } else {
                    direction = 'L';
                }
            } else if (direction == 'S'){
                if (command=='E'){
                    direction = 'L';
                } else {
                    direction = 'O';
                }
            } else if (direction == 'L'){
                if (command=='E'){
                    direction = 'N';
                } else {
                    direction = 'S';
                }
            } else {
                if (command=='E'){
                    direction = 'S';
                } else {
                    direction = 'N';
                }
            }
        }
};

int main(){
    int n, m, s;
    char map[101][101];
    char command;
    Robot robo;
    do{
        scanf("%d %d %d ", &n, &m, &s);
        for (int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                scanf("%c ", &map[i][j]);
                if (map[i][j]=='N' || map[i][j]=='S' || map[i][j]=='L' || map[i][j]=='O'){
                    robo.vertical = i;
                    robo.horizontal=j;
                    robo.direction = map[i][j];
                    robo.stickers = 0;
                }
            }
        }
        for (int k = 0; k<s; k++){
            scanf(" %c ", &command);
            if (command=='F') {
                robo.walk(map, n, m);
                //cout << map[robo.vertical][robo.horizontal];
                if (map[robo.vertical][robo.horizontal] == '*'){
                    robo.stickers++;
                    map[robo.vertical][robo.horizontal] = ' ';
                } 
            } else {
                robo.changedir(command);
                //cout << map[robo.vertical][robo.horizontal];
            }
        }
        if (s!=0 && n!=0 && m!=0){
            printf("%d\n", robo.stickers);
        }
    }while(n!=0 && m!=0 && s!=0);

    return 0;
}
