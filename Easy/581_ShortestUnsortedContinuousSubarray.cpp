#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//��˼·�����򣬲���time_limit_exceed.

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

//ʹ��stackʵ�ֵ�˼·��ʱ�临�Ӷ���O(n)��
//ʹ������stack���ֱ�ó�����ҵ�λ�á�
//�Ƚ�ָ���ջ������һ�����ݱ�ջ������С���ͽ�ջ��ָ�벻�ϳ�ջ��Ȼ����l�洢�Ӵ���ͷָ�롣
//�Ӵ���βָ���ǰ��ͬ��
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

