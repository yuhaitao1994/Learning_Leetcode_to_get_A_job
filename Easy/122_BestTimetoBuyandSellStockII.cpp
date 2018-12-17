#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//122. Best Time to Buy and Sell Stock II������ǰһ���˼·��ͬ��ǰһ������һ�����Ĳ������������ĺ͡�
//������������ֲ�������ͼ�����ֻҪ���ּ�С���ͰѴ˴εĲ�ֵ��������Ȼ�������ͷ������������
//��ǰһ�������ǰһ���������һ�����ֱ�֮ǰ��С�����ֻ�С�������¿�ʼ��������ֻҪ��ǰһ������С�������¿�ʼ��
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
