#include <cstdio>

int main() {
    int hi, mi, hf, mf, dh, dm;
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    if (hf - hi > 0) {
        dh = hf-hi;
    } else {
        dh = 24 - hi + hf;
    }

    if (mf - mi > 0) {
        dm = mf-mi;
    } else {
        dh--;
        dm = mf - mi + 60;
        if (dm == 60) {
            dh++;
            dm = 0;
        }
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dh, dm);

    return 0;
}
