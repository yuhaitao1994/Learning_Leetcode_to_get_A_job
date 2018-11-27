#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//思路很简单，就是有一点不小心数组溢出了，就是遍历，定义一个crowd，遇到0就凑一起，遇到不是0就把当前的第一个0和这个
//数交换，最后得到序列后面都是0.
//Runtime: 12 ms, faster than 61.99% of C++ online submissions for Move Zeroes.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int crowd=0;
        int transfer;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0){
                if(nums[i+1]!=0){
                    transfer=nums[i+1];
                    nums[i+1]=nums[i-crowd];
                    nums[i-crowd]=transfer;
                }
                else
                    crowd++;
            }
            else{
                continue;
            }
        }
    }
};

int main()
{
    int aa[10]={4,2,4,0,0,3,0,5,1,0};
    vector<int> a(aa,aa+sizeof(aa)/sizeof(int));
    Solution so;
    so.moveZeroes(a);
    for(int i=0;i<10;i++)
        cout<<a[i];
    system("pause");
}
