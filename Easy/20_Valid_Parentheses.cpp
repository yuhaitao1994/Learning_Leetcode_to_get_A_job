#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

# 解决方案，采用栈分别存储三种左括号，当遇到右括号时，找对应的。

class Solution {
public:
    bool isValid(string s) {
        if(s==""){
            return true;
        }
        stack<int> small;
        stack<int> mid;
        stack<int> big;
        small.push(-1);
        mid.push(-1);
        big.push(-1);
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                small.push(i);
            }
            else if(s[i]=='['){
                mid.push(i);
            }
            else if(s[i]=='{'){
                big.push(i);
            }
            else if(s[i]==')'){
                if(small.top()>mid.top()&&small.top()>big.top()){
                    small.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(mid.top()>small.top()&&mid.top()>big.top()){
                    mid.pop();
                }
                else{
                    return false;
                }
            }
            else{
                if(big.top()>mid.top()&&big.top()>small.top()){
                    big.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(small.top()==-1&&mid.top()==-1&&big.top()==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    string a="{[]}";
    Solution so;
    cout<<boolalpha<<so.isValid(a)<<endl;
    system("pause");
}
