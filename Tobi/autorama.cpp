#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

struct car{
  int id;
  int pos;
  int ans;
  int time;
};

bool comp(car a, car b){
  if(a.ans != b.ans)
    return (a.ans > b.ans);
  else return (a.time < b.time);
}

vector<car> v(101);
vector<bool> vs(101, true);

int main(){
  std::ios::sync_with_stdio(false);
  int k, n, m, x, y, timev;
  cin >> k >> n >> m;
  timev = 0;
  while(m--){
    timev++;
    cin >> x >> y;
    v[x].id = x;
    if(y == (v[x].pos)%k + 1 || (y==1 && vs[x])){
        v[x].pos = y;
        if(vs[x]) v[x].ans = 1;
        else
            v[x].ans++;
      v[x].time = timev;      
    }
    vs[x] = false;
    //cout << x << " " << y << " " << v[x].id << " " << v[x].pos << "\n";
  }
  /*
  for(int i=1; i<=n; i++)
   cout << v[i].pos << " " << v[i].id << " ";
  cout << "\n";
  */
  sort(v.begin()+1, v.begin()+n+1, comp);
  /*
  for(int i=1; i<=n; i++)
   cout << v[i].pos << " " << v[i].id << " ";
  cout << "\n";
  */

  for(int i=1; i<=n; i++){
    if(i!=n)
      cout << v[i].id << " ";
    else
      cout << v[i].id << "\n";
  }
}
