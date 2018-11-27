#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//这道题一开始没想出来，是一道标准的动态规划问题。
//每次新读入一个数，都将这个数加上两步之前的最大值，与一步之前的最大值比较，取新的最大值。
//Runtime: 4 ms, faster than 18.11% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int max_1=nums[0];
        int max_2=max(nums[0],nums[1]);
        int m;
        for(int i=2;i<nums.size();i++){
            m=max_2;
            max_2=max(max_1+nums[i],m);
            max_1=m;
        }
        return max_2;
    }
};

int main()
{
    int a[6]={};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    Solution so;
    cout<<so.rob(nums)<<endl;
    system("pause");
}
