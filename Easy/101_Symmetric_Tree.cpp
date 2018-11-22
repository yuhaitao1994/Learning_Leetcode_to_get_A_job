#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//递归的方式，对比左子树的左儿子和右子树的右儿子，就是在判断true和false的时候需要仔细考虑一下。


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(!root->left&&!root->right)
            return true;
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        return l_and_r(l, r);
    }
    bool l_and_r(TreeNode* l, TreeNode *r){
        if(!l&&!r)
            return true;
        if((l&&!r)||(!l&&r))
            return false;
        else{
            if(l->val!=r->val)
            return false;
            else{
                if(!l->left&&!l->right&&!r->left&&!r->right)
                    return true;
                else{
                    if(l_and_r(l->left,r->right)==false||l_and_r(l->right,r->left)==false)
                        return false;
                    else
                        return true;
                }
            }
        }
    }
};

int main()
{
    TreeNode *root;
    Solution so;
    cout<<so.isSymmetric(root)<<endl;
    system("pause");
}
