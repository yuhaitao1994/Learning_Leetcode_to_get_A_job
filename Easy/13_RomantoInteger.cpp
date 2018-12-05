#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//思路比较简单，但是这道题的测试用例没有考虑全
//比如IXL，测试程序的结果是39，即50-10-1，本程序结果是59，即9+50.不过这种情况在测试中没有，测试中都是正常情况。
//Runtime: 56 ms, faster than 65.23% of C++ online submissions for Roman to Integer.

class Solution {
public:
    int romanToInt(string s) {
        int Int=0;
        int i=0;
        for(i;i<s.length()-1;i++){
            if(s[i]=='I'){
                switch(s[i+1]){
                    case 'V':
                        Int+=4;
                        i++;
                        break;
                    case 'X':
                        Int+=9;
                        i++;
                        break;
                    case 'L':
                        Int+=49;
                        i++;
                        break;
                    case 'C':
                        Int+=99;
                        i++;
                        break;
                    case 'D':
                        Int+=499;
                        i++;
                        break;
                    case 'M':
                        Int+=999;
                        i++;
                        break;
                    default:
                        Int+=1;
                        break;
                }
            }
            else if(s[i]=='V'){
                switch(s[i+1]){
                    case 'X':
                        Int+=5;
                        i++;
                        break;
                    case 'L':
                        Int+=45;
                        i++;
                        break;
                    case 'C':
                        Int+=95;
                        i++;
                        break;
                    case 'D':
                        Int+=495;
                        i++;
                        break;
                    case 'M':
                        Int+=995;
                        i++;
                        break;
                    default:
                        Int+=5;
                        break;
                }
            }
            else if(s[i]=='X'){
                switch(s[i+1]){
                    case 'L':
                        Int+=40;
                        i++;
                        break;
                    case 'C':
                        Int+=90;
                        i++;
                        break;
                    case 'D':
                        Int+=490;
                        i++;
                        break;
                    case 'M':
                        Int+=990;
                        i++;
                        break;
                    default:
                        Int+=10;
                        break;
                }
            }
            else if(s[i]=='L'){
                switch(s[i+1]){
                    case 'C':
                        Int+=50;
                        i++;
                        break;
                    case 'D':
                        Int+=450;
                        i++;
                        break;
                    case 'M':
                        Int+=950;
                        i++;
                        break;
                    default:
                        Int+=50;
                        break;
                }
            }
            else if(s[i]=='C'){
                switch(s[i+1]){
                    case 'D':
                        Int+=400;
                        i++;
                        break;
                    case 'M':
                        Int+=900;
                        i++;
                        break;
                    default:
                        Int+=100;
                        break;
                }
            }
            else if(s[i]=='D'){
                switch(s[i+1]){
                    case 'M':
                        Int+=500;
                        i++;
                        break;
                    default:
                        Int+=500;
                        break;
                }
            }
            else{
                Int+=1000;
            }
        }
        if(i>s.length()-1) return Int;
        else{
            switch(s[i]){
                case 'I':
                    Int+=1;
                    break;
                case 'V':
                    Int+=5;
                    break;
                case 'X':
                    Int+=10;
                    break;
                case 'L':
                    Int+=50;
                    break;
                case 'C':
                    Int+=100;
                    break;
                case 'D':
                    Int+=500;
                    break;
                case 'M':
                    Int+=1000;
                    break;
            }
            return Int;
        }
    }
};

int main()
{
    string a="IIIIIIVXXCDMMIVCD";
    Solution so;
    int laji=so.romanToInt(a);
    cout<<laji<<endl;
    system("pause");
}
