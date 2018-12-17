#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//BST，二叉搜索树，左子树永远比根的小，右子树永远比根大
//平衡的BST，要求左右子树的深度不超过1
//所以考虑用递归的方法，不断的二分数组。
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Convert Sorted Array to Binary Search Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return nullptr;
        return BST(nums, 0, len-1);
    }
    TreeNode* BST(vector<int>& nums, int start, int end){
        if(start>end)
            return nullptr;
        if(start==end){
            TreeNode* root=new TreeNode(nums[start]);
            root->left=nullptr;
            root->right=nullptr;
            return root;
        }
        else{
            TreeNode* root=new TreeNode(nums[(start+end)/2]);
            root->left=BST(nums, start, (start+end)/2-1);
            root->right=BST(nums, (start+end)/2+1, end);
            return root;
        }
    }
};
