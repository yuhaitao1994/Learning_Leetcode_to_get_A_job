#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//简单的思路
//Runtime: 4 ms, faster than 50.38% of C++ online submissions for Hamming Distance.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming=0;
        while(x!=0||y!=0){
            hamming+=((x%2)^(y%2));
            x=x/2;
            y=y/2;
        }
        return hamming;
    }
};

int main()
{
    int a=0;
    int b=2147483647;
    Solution so;
    cout<<so.hammingDistance(a,b);
    system("pause");
}
