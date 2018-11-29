#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//简单思路，用一个递归。缺点是不太快。
//Runtime: 44 ms, faster than 37.95% of C++ online submissions for Merge Two Binary Trees.

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        struct TreeNode *root;
        if(t1){
            root=t1;
            if(t2){
                root->val=t1->val+t2->val;
                root->left=mergeTrees(t1->left,t2->left);
                root->right=mergeTrees(t1->right,t2->right);
            }
            else{
                root->val=t1->val;
                root->left=mergeTrees(t1->left,nullptr);
                root->right=mergeTrees(t1->right,nullptr);
            }
        }
        else{
            root=t2;
            if(t2){
                root->val=t2->val;
                root->left=mergeTrees(nullptr,t2->left);
                root->right=mergeTrees(nullptr,t2->right);
            }
            else{
                return nullptr;
            }
        }
        return root;
    }
};
