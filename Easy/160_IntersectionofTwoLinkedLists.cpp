#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//先遍历A和B分别得到两个链表的长度，然后在从相同长度处开始遍历。
//You are here! Your runtime beats 86.96 % of cpp submissions.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL;
        ListNode *pa=headA;
        ListNode *pb=headB;
        int a_len=0;
        int b_len=0;
        while(headA||headB){
            if(headA){
                a_len+=1;
                headA=headA->next;
            }
            if(headB){
                b_len+=1;
                headB=headB->next;
            }
        }
        if(a_len>=b_len){
            for(int i=0;i<(a_len-b_len);i++)
                pa=pa->next;
        }
        else{
            for(int i=0;i<(b_len-a_len);i++)
                pb=pb->next;
        }
        while(pa&&pb){
            if(pa==pb) return pa;
            else{
                pa=pa->next;
                pb=pb->next;
            }
        }
        return NULL;
    }
};

