#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//思路很简单，用一个stack来实现。
//Runtime: 12 ms, faster than 98.51% of C++ online submissions for Palindrome Linked List.

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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *p=head;
        while(p){
            st.push(p->val);
            p=p->next;
        }
        while(head){
            if(st.top()!=head->val) return false;
            st.pop();
            head=head->next;
        }
        return true;
    }
};
