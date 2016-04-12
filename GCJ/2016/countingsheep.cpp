#include <iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n, m = 0, ans = 0;
        cin >> n;
        int v[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        if (n == 0) {
            cout << "Case #" << k+1 << ": INSOMNIA" << endl;
            continue;
        }
        while (ans < 10) {
            m += n;
            int aux = m;
            while (aux > 0) {
                if (!v[aux%10]) {
                    v[aux%10] = 1;
                    ans++;
                }
                aux /= 10;
            }
        }
        cout << "Case #" << k+1 << ": " << m << endl;
    }
}
