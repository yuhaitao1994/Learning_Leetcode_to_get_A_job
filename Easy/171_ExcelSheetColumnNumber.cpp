#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//简单的26进制数。
//Runtime: 4 ms, faster than 98.98% of C++ online submissions for Excel Sheet Column Number.

class Solution {
public:
    int titleToNumber(string s) {
        long long int num=0;
        long long int a=1;
        for(int i=s.length()-1;i>=0;i--){
            num+=(s[i]-'A'+1)*a;
            a*=26;
        }
        return num;
    }
};
