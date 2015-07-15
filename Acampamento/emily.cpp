#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    long long int n, a, cur, max, ans, tmp;
    queue<long long int> s;

    scanf("%lld", &n);

    while(n--) {
        scanf("%lld", &a);
        ans = 0;
        max = 0;
        
        while(a--) {
            scanf("%lld", &cur);
            if(find(s.front(), s.back()+1, cur)!=s.back()+1){
                s.push(cur);
            }
            else{
                tmp = s.pop();
                while(tmp!=cur){
                    tmp = s.pop();
                }
                s.push(cur);
            }
            ans =+ s.size();
            if(ans>max) max = ans;
        }

        printf("%lld\n", max);
    }

    return 0;
}
