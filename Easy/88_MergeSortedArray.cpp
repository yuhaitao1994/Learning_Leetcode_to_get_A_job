#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//先把nums1中的数存到另一个容器中，然后在两个容器按大小顺序取数往nums1中放。
//Runtime: 4 ms, faster than 99.40% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        for(int i=0;i<m;i++) nums3.push_back(nums1[i]);
        int a=0,b=0,index=0;
        while(a!=m&&b!=n){
            if(nums3[a]<nums2[b]){
                nums1[index]=nums3[a];
                a++;
            }
            else{
                nums1[index]=nums2[b];
                b++;
            }
            index++;
        }
        if(a==m){
            while(b!=n){
                nums1[index]=nums2[b];
                b++;
                index++;
            }
        }
        else{
            while(a!=m){
                nums1[index]=nums3[a];
                a++;
                index++;
            }
        }
    }
};
