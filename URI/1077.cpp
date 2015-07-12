#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool prior(char a, char b){
    if(b=='('){
        return true;
    }
    if(a=='^'){
        return true;
    } else if(a=='*' || a=='/'){
        if(b=='+' || b=='-'){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    int n;
    string ans;
    string exp;
    string stack;
    scanf("%d ", &n);
    for(int i = 0; i<n; i++){
        cin >> exp;
        stack = "";
        ans = "";
        for(int j = 0; j<exp.length(); j++){
            if(exp[j] == ')'){
                ans+=stack.substr(0, stack.find("("));
                stack.erase(0, stack.find("(")+1);
            }
            else if(exp[j] == '^'){
                stack = exp[j] + stack;
            } 
            else if(exp[j] == '/'){
                while(!prior(exp[j], stack[0]) && stack.length()>0){
                    ans += stack[0];
                    stack.erase(0, 1);
                }
                stack = exp[j] + stack;
            }
            else if(exp[j] == '*'){
                while(!prior(exp[j], stack[0]) && stack.length()>0){
                    ans += stack[0];
                    stack.erase(0, 1);
                }
                stack = exp[j] + stack;
            }
            else if(exp[j] == '+'){
                while(!prior(exp[j], stack[0]) && stack.length()>0){
                    ans += stack[0];
                    stack.erase(0, 1);
                }
                stack = exp[j] + stack;
            }
            else if(exp[j] == '-'){
                while(!prior(exp[j], stack[0]) && stack.length()>0){
                    ans += stack[0];
                    stack.erase(0, 1);
                }
                stack = exp[j] + stack;
            }
            else if(exp[j]=='('){
                stack = exp[j] + stack;
            }
            else {
                ans += exp[j];
            }
            //cout << ans << endl << stack << endl;
        }
        ans += stack;
        cout << ans << endl;
    }
    return 0;
}
