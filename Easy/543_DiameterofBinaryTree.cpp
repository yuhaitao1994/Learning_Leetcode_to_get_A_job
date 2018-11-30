#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//题目描述为：任意两个叶子节点到第一个公共祖先节点的距离和的最大值。
//采用递归的方法，但是自己一直没有想到特别好的递归思路。
//采用别人的递归思路，递归过程中返回的是每个子树的最大深度，但是在返回深度之前，要先计算max和a+b的关系。
//max是在整个函数过程中用来存最大长度的变量，注意在声明函数是要用int &max，表明所有的处理都是处理一个地址的变量。
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Diameter of Binary Tree.

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int max=0;
        find(root,max);
        return max;
    }
    int find(TreeNode* t, int &max){
        int a=0, b=0;
        if(!t->left&&!t->right) return 0;
        if(t->left) a=find(t->left, max)+1;
        if(t->right) b=find(t->right, max)+1;
        if(max<(a+b)) max=a+b;
        if(a>=b) return a;
        else return b;
    }
};
