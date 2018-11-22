#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

# 我这个方法想麻烦了，实际上就是每加一个数，对比前面的最大值和加上这个数之后的值哪个大，最终选
# 的最大值就是maxSubArray。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int head=0;
        int tail=0;
        int max_value=nums[0];
        int current_value=nums[0];
        int len = nums.capacity();
        for(int i=1;i<len;i++){
            tail=i;
            if(nums[i]>0){
                int new_current=nums[i];
                for(int j=tail-1;j>=head;j--){
                    if(new_current>(current_value+new_current)){
                        head=j+1;
                        current_value=new_current;
                        if(new_current>max_value)
                            max_value=new_current;
                        break;
                    }
                    else{
                        new_current+=nums[j];
                        current_value-=nums[j];
                    }
                }
                current_value=new_current;
                if(new_current>max_value){
                    max_value=new_current;
                }
            }
            else{
                if(nums[i]>current_value){
                    current_value=nums[i];
                    head=i;
                }
                else{
                    current_value+=nums[i];
                }
            }
            if(current_value>max_value)
                max_value=current_value;
        }
        return max_value;
    }
};

int main()
{
    int aa[8]={-2,1,-3,4,-1,2,-5,4};
    vector<int> a(aa,aa+sizeof(aa)/sizeof(int));
    Solution so;
    cout<<so.maxSubArray(a)<<endl;
    system("pause");
}
