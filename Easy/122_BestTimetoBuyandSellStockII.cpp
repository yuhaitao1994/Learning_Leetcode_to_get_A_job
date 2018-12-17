#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//122. Best Time to Buy and Sell Stock II这道题和前一题的思路相同，前一题是求一个最大的差，此题是求多个差的和。
//遍历，如果数字不断增大就继续，只要数字减小，就把此次的差值存起来，然后更换开头，继续遍历。
//与前一题的区别，前一题是如果下一个数字比之前最小的数字还小，则重新开始，本题是只要比前一个数字小，就重新开始。
//Runtime: 4 ms, faster than 99.08% of C++ online submissions for Best Time to Buy and Sell Stock II.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int onetime=0;
        int maxprofit=0;
        for(int i=1;i<prices.capacity();i++){
            if(prices[i]<prices[i-1]){
                buy=i;
                maxprofit+=onetime;
                onetime=0;
            }
            else{
                if(prices[i]-prices[buy]>onetime){
                    onetime=prices[i]-prices[buy];
                }
            }
        }
        maxprofit+=onetime;
        return maxprofit;
    }
};
