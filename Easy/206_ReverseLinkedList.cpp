#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//定义一个stack即可实现反向。
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p=head;
        ListNode *q=head;
        stack<int> st;
        while(p){
            st.push(p->val);
            p=p->next;
        }
        while(q){
            q->val=st.top();
            st.pop();
            q=q->next;
        }
        return head;
    }
};
