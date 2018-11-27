#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//这个思路简单，但是显然不是好的思路，先创建一个[1,n]的vector
//然后找在原始序列中出现的就删掉，剩下的就是没出现的。
//学习到了关于vector容器的遍历，删除，添加等操作，就是耗时太多。
//Runtime: 444 ms, faster than 1.31% of C++ online submissions for Find All Numbers Disappeared in an Array.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappear;
        for(int i=0;i<nums.size();i++){
            disappear.push_back(1);
        }
        for(int i=0;i<nums.size();i++){
            disappear[nums[i]-1]=0;
        }
        std::vector<int>::iterator it=disappear.begin();
        int index=0;
        while(it!=disappear.end()){
            if(*it==0){
                disappear.erase(it);
            }
            else{
                *it=index+1;
                it++;
            }
            index++;
        }
        return disappear;
    }
};

//看来vector容器的erase方法很耗费时间，改成新添一个vector存最终结果，速度明显加快。
//Runtime: 104 ms, faster than 54.75% of C++ online submissions for Find All Numbers Disappeared in an Array.
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappear;
        vector<int> returnvec;
        for(int i=0;i<nums.size();i++){
            disappear.push_back(1);
        }
        for(int i=0;i<nums.size();i++){
            disappear[nums[i]-1]=0;
        }
        for(int i=0;i<nums.size();i++){
            if(disappear[i]==1)
                returnvec.push_back(i+1);
        }
        return returnvec;
    }
};

int main()
{
    int aa[4]={1,2,3,3};
    vector<int> a(aa,aa+sizeof(aa)/sizeof(int));
    Solution so;
    vector<int> b=so.findDisappearedNumbers(a);
    for(int i=0;i<b.size();i++)
        cout<<b[i];
    system("pause");
}
