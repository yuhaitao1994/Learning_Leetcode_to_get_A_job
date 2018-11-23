#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//����һ��map�����д洢��
//��õķ�������xor�������е��������������ս������single number��
//Runtime: 20 ms, faster than 15.15% of C++ online submissions for Single Number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int,int> umap;
        for(int i=0;i<nums.capacity();i++){
            umap[nums[i]]+=1;
        }
        std::map<int,int>::iterator it=umap.begin();
        while(it!=umap.end()){
            if(it->second==1)
                return it->first;
            it++;
        }
    }
};

int main()
{
    int a[7]={3,1,1,4,2,4,3};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    Solution so;
    cout<<so.singleNumber(nums)<<endl;
    system("pause");
}
