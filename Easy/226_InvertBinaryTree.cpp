#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//递归，交换左右孩子节点。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left&&!root->right) return root;
        TreeNode *p;
        p=invertTree(root->left);
        root->left=invertTree(root->right);
        root->right=p;
        return root;
    }
};
