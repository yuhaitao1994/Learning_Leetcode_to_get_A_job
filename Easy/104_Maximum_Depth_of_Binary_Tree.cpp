#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//简单的递归，就是递归速度有点慢。

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

int main()
{
    TreeNode *root;
    Solution so;
    cout<<so.isSymmetric(root)<<endl;
    system("pause");
}
