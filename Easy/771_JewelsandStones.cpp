#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//定义两个vector容器存S中各个字母出现次数即可，时间复杂度O(n)
//Runtime: 4 ms, faster than 98.61% of C++ online submissions for Jewels and Stones.

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> low(26,0), high(26,0);
        for(int i=0;i<S.length();i++){
            if(S[i]-'a'<0) high[S[i]-'A']++;
            else low[S[i]-'a']++;
        }
        int num=0;
        for(int i=0;i<J.length();i++){
            if(J[i]-'a'<0) num+=high[J[i]-'A'];
            else num+=low[J[i]-'a'];
        }
        return num;
    }
};
