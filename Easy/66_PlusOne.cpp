#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//主要考虑当数字是9的时候的进位问题，用两个vector存储，reverse存储倒序的，如果有进位就多存一位。
//定义一个flag为1，当数字是9时，加1进位，flag保持不变，当数字不是9时，加1不进位，flag置0.
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> reverse;
        vector<int> output;
        int flag=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                if(flag==1) reverse.push_back(0);
                else reverse.push_back(digits[i]);
            }
            else{
                reverse.push_back(digits[i]+flag);
                flag=0;
            }
        }
        if(flag==1)
            reverse.push_back(1);
        for(int i=reverse.size()-1;i>=0;i--)
            output.push_back(reverse[i]);
        return output;
    }
};
