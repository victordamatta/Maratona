#include <bits/stdc++.h>
using namespace std;

long long n, dist[100007];

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    long long aux, aux2;
    dist[0] = 0;
    cin >> aux;
    for(long long i=1; i<n; i++){
        cin >> aux2;
        dist[i] = aux2-aux;
        aux = aux2;
    }
    for(long long i=1; i<n; i++){
        dist[i]+=dist[i-1];
    }
    long long mini, maxi;
    mini = dist[1];
    maxi = dist[n-1];
    cout << mini << " " << maxi << "\n";
    for(long long i=1; i<n-1; i++){
        mini = min(dist[i]-dist[i-1], dist[i+1]-dist[i]);
        maxi = max(dist[n-1]-dist[i], dist[i]);
        cout << mini << " " << maxi << "\n";
    }
    mini = dist[n-1] - dist[n-2];
    maxi = dist[n-1];
    cout << mini << " " << maxi << "\n";
    return 0;
}
