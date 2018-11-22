#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

# a(n)=a(n-1,1)*2 + a(n-1,2)*1

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int a1[n];
        int a2[n];
        a1[1]=1;
        a2[1]=1;
        for(int i=2;i<n;i++){
            a1[i]=a1[i-1]+a2[i-1];
            a2[i]=a1[i-1];
        }
        return (a1[n-1]+a2[n-1]);
    }
};

int main()
{
    int a=2;
    Solution so;
    cout<<so.climbStairs(a)<<endl;
    system("pause");
}
