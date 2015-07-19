#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    long int n;
    while(cin>>n, n!=0){
      if(n==1 || n==2)
        printf("Alice\n");
      else
        printf("Bob\n");
    }
}
