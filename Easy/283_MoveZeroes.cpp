#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//˼·�ܼ򵥣�������һ�㲻С����������ˣ����Ǳ���������һ��crowd������0�ʹ�һ����������0�Ͱѵ�ǰ�ĵ�һ��0�����
//�����������õ����к��涼��0.
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
