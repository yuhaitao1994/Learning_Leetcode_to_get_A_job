#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//��Ҫ���ǵ�������9��ʱ��Ľ�λ���⣬������vector�洢��reverse�洢����ģ�����н�λ�Ͷ��һλ��
//����һ��flagΪ1����������9ʱ����1��λ��flag���ֲ��䣬�����ֲ���9ʱ����1����λ��flag��0.
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
