#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fst first
#define scd second
#define f(fst, let) for(int let=0; let<fst; let++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

struct seg {
    int size;
    pi f;
    pi s;
};

bool cmp (seg a, seg b) {
    return a.size < b.size;
}

pi ps[2007];
seg ss[6000000];

int main(){
    std::ios::sync_with_stdio(false);
    int t, n;
    int ssz;
    cin >> t;
    f(t, j) {
        ssz = 0;
        cin >> n;
        f(n, i) {
            int g, h;
            cin >> g >> h;
            ps[i].fst = g;
            ps[i].scd = h;
        }
        f(n, i) {
            for(int k = i+1; k < n; k++){
                ss[ssz].f = ps[i];
                ss[ssz].s = ps[k];
                ss[ssz].size = (ps[k].fst - ps[i].fst)*(ps[k].fst - ps[i].fst) + (ps[k].scd - ps[i].scd)*(ps[k].scd - ps[i].scd);
                ssz++;
            }
        }
        sort (ss, ss+ssz, cmp);
        int siz, i = 0;
        int ans = 0;
        while (i < ssz) {
            map<pi, int> s;
            siz = ss[i].size;
            while (i < ssz && ss[i].size == siz) {
                if(s.find(ss[i].f) != s.end()) ans+=s[ss[i].f];
                if(s.find(ss[i].s) != s.end()) ans+=s[ss[i].s];
                s[ss[i].f]++;
                s[ss[i].s]++;
                i++;
            }
        }
        cout << "Case #" << j+1 << ": " << ans << "\n";
    }
}
