#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//简单思路，排序，不过time_limit_exceed.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        vector<int> sorted=nums;
        for(int i=0;i<sorted.size()-1;i++){
            for(int j=0;j<sorted.size()-i-1;j++){
                if(sorted[j]>sorted[j+1]){
                    sorted[j]=sorted[j]^sorted[j+1];
                    sorted[j+1]=sorted[j]^sorted[j+1];
                    sorted[j]=sorted[j]^sorted[j+1];
                }
            }
        }
        int head=0;
        int tail=nums.size()-1;
        while((nums[head]==sorted[head])&&(head<tail)) head++;
        while((nums[tail]==sorted[tail])&&(head<tail)) tail--;
        if(head>=tail) return 0;
        else return tail-head+1;
    }
};

//使用stack实现的思路，时间复杂度是O(n)。
//使用两次stack，分别得出左和右的位置。
//先将指针进栈，当下一个数据比栈顶数据小，就将栈顶指针不断出栈，然后用l存储子串的头指针。
//子串的尾指针和前面同理。
//Runtime: 28 ms, faster than 75.10% of C++ online submissions for Shortest Unsorted Continuous Subarray.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int l=nums.size(), r=0;
        for(int i=0;i<nums.size();i++){
            while(st.empty()==0 && nums[st.top()]>nums[i]){
                l=std::min(l,st.top());
                st.pop();
            }
            st.push(i);
        }
        while(st.empty()==0)
            st.pop();
        for(int i=nums.size()-1;i>=0;i--){
            while(st.empty()==0 && nums[st.top()]<nums[i]){
                r=max(r,st.top());
                st.pop();
            }
            st.push(i);
        }
        if(r>l) return r-l+1;
        else return 0;
    }
};

