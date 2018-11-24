#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

// π”√map
//Runtime: 12 ms, faster than 97.72% of C++ online submissions for Majority Element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> umap;
        for(int i=0;i<nums.capacity();i++)
            umap[nums[i]]++;
        std::map<int,int>::iterator it=umap.begin();
        int max_num=0;
        int major;
        while(it!=umap.end()){
            if(it->second>max_num){
                max_num=it->second;
                major=it->first;
            }
            it++;
        }
        return major;
    }
};

int main()
{
    int a[7]={2,2,1,1,1,2,2};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    Solution so;
    cout<<so.majorityElement(nums)<<endl;
    system("pause");
}
