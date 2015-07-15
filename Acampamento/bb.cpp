#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;


int main() {
    string a;
    map<string, string> dict;
    char b, c[12] = {0,0,0,0,0,0,0,0,0,0,0,0}, d[12] = {0,0,0,0,0,0,0,0,0,0,0,0}, *e;
    int quebra = 0, i;

    e = c;
    i = 0;

    while(1) {
        scanf("%c", &b);

            if (b == '\n' && quebra == 0) {
                string aux(c);
                string aux2(d);

                dict[aux2] = aux;

                quebra = 1;
                i = 0;
                e = c;

            } else if (b == '\n' && quebra == 1) {
                break;

            } else if (b == ' ') {
                e = d;
                i = 0;

            } else {
                e[i++] = b;
                quebra = 0;

            }
    }

    while(cin >> a) {
        if (dict.count(a) > 0) cout << dict[a] << endl;
        else printf("eh\n");
    }

    return 0;
}
