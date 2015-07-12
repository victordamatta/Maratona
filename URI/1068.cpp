#include <cstdio>
#include <string>
#include <iostream>

int main() {
    char s[1000];
    std::string Str;
    int c = 0;

    while (scanf(" %s", s) != EOF) {

        Str = s;
        c = 0;

        for(unsigned int i = 0; i < Str.length(); i++) {
            if(Str[i] == '(') {
                c++;
            } else if(Str[i] == ')') {
                c--;
            }
            if(c < 0) {
                break;
            }
        }

        if(c == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}
