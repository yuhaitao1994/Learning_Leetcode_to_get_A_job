#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//��Ŀ����Ϊ����������Ҷ�ӽڵ㵽��һ���������Ƚڵ�ľ���͵����ֵ��
//���õݹ�ķ����������Լ�һֱû���뵽�ر�õĵݹ�˼·��
//���ñ��˵ĵݹ�˼·���ݹ�����з��ص���ÿ�������������ȣ������ڷ������֮ǰ��Ҫ�ȼ���max��a+b�Ĺ�ϵ��
//max��������������������������󳤶ȵı�����ע��������������Ҫ��int &max���������еĴ����Ǵ���һ����ַ�ı�����
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
