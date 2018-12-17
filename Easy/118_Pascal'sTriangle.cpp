#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//每个新的vector都有前一个vector得到，以此类推再合成输出。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        if(numRows==0) return output;
        vector<int> pre;
        pre.push_back(1);
        output.push_back(pre);
        for(int i=1;i<numRows;i++){
            vector<int> current;
            for(int j=0;j<i+1;j++){
                if(j==0||j==i) current.push_back(1);
                else current.push_back(pre[j-1]+pre[j]);
            }
            output.push_back(current);
            pre=current;
        }
        return output;
    }
};
