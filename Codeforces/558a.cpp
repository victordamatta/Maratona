#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int v[200003], n, l, r, aux1, aux2, tl, tr;
vector<long int> sl, sr;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    l = r = tl = tr = 0;
    while(n--){
        cin >> aux1 >> aux2;
        if(aux1<0){
            l++;
            tl += aux2;
            sl.push_back(-aux1);
            v[100001+aux1] = aux2;
        }
        else{
            r++;
            tr += aux2;
            sr.push_back(aux1);
            v[100001+aux1] = aux2;
        }
    }
    sort(sr.begin(), sr.end());
    sort(sl.begin(), sl.end());
    long long int ans;
    if(l<r){
        ans = tl;
        vector<long int>::iterator it = sr.begin();
        for(int i=0; i<l+1; i++){
            ans += v[100001 + *(it+i)];
        }
    }
    else if(r < l){
        ans = tr;
        vector<long int>::iterator it = sl.begin();
        for(int i=0; i<r+1; i++){
            ans += v[100001 - *(it+i)];
        }
    }
    else{
        ans = tl + tr;
    }
    cout << ans << "\n";
}
