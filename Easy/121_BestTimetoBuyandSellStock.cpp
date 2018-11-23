#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//简单的一次遍历，时间复杂度O(n)
//Runtime: 8 ms, faster than 38.51% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int maxprofit=0;
        for(int i=1;i<prices.capacity();i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            else{
                if(prices[i]-prices[buy]>maxprofit)
                    maxprofit=prices[i]-prices[buy];
            }
        }
        return maxprofit;
    }
};

int main()
{
    int a[3]={7,6,5};
    vector<int> price(a,a+sizeof(a)/sizeof(int));
    Solution so;
    cout<<so.maxProfit(price)<<endl;
    system("pause");
}
