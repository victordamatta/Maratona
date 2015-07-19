#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, t;
int p, q, id, ids[20];
pair<int, int> mat[111][111];
int vpd[10][111][1011];

int pd(int x, int y, int mon){
    if(mon < 0) return 0;
    if(x>6) return INT_MAX;
    if(y==ids[x]) return 0;
    if(vpd[x][y][mon] != -1) return vpd[x][y][mon];

    int res = max(min(mat[x][y].second, pd(x+1, 0, mon-mat[x][y].first)), pd(x, y+1, mon));
    vpd[x][y][mon] = res;
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> t;
    memset(ids, 0, sizeof ids);
    memset(vpd, -1, sizeof vpd);
    for(int i=0; i<n; i++){
        cin >> id >> p >> q;
        mat[id][ids[id]] = make_pair(p, q);
        ids[id]++;
    }
    int res;
    res = pd(1, 0, t);
    cout << res << "\n";

}
