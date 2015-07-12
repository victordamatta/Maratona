#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int main(){
    int n, index, clean, counter, temp;
    int indexes[50], sizes[50];
    string input;
    scanf("%d ", &n);
    for(int i = 0; i<n; i++){
        getline(cin, input);
        index = clean = counter = 0;
        for(int l = 0; l<50; l++){
            indexes[l] = 0;
            sizes[l] = 0;
        }
        for(int j = 0; j<input.length(); j++){
            if(input[j]!=' '){
                sizes[index]+=1;
            }
            else{
                index++;
            }
        }
        for(int k = 0; k<index+1; k++){
            indexes[k] = k;
        }
        string buf;
        stringstream ss(input);
        vector<string> tokens;
        while(ss >> buf)
            tokens.push_back(buf);
        while(clean == 0){
            clean = 1;
            for(int counter = 0; counter<index+1; counter++){
                if(sizes[counter]<sizes[counter+1]){
                    temp = sizes[counter];
                    sizes[counter] = sizes[counter+1];
                    sizes[counter+1] = temp;
                    temp = indexes[counter];
                    indexes[counter] = indexes[counter+1];
                    indexes[counter+1] = temp;
                    clean = 0;
                }
            }
        }
        for(int x = 0; x<(index+1); x++){
            //cout << indexes[x] << " ";
            if(x!=index)
                cout << tokens[indexes[x]] << " ";
            else 
                cout << tokens[indexes[x]] << endl;
        }
    }
}
