#include <iostream>
#define f(x, let) for(int let=0; let<x; let++)
using namespace std;
typedef long long ll;

ll bs[100007];

int main(){
    std::ios::sync_with_stdio(false);
    ll ans, p;
    int t, n;
    cin >> t;
    f(t, k){
        cin >> n >> p;
        ans = n*(n+1)/2;
        int p1 = 0, p2 = 0;
        f(n, i) cin >> bs[i];
        ll sum = bs[0];
        while (p1 < n) {
            if(p2 == n && sum <= p) break;
            while (p2 < n && sum <= p) {
                p2++;
                sum += bs[p2];
            }
            ans -= n - p2;
            sum -= bs[p1];
            p1++;
        }
        cout << "Case #" << k+1 << ": " << ans << "\n";
    }
}
