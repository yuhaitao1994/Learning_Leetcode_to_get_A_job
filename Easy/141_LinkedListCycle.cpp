#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//使用两个指针，第一个指针一次跳一步，第二个指针一次跳两步，如果存在环路，两个指针一定会有重合的时候。
//Your runtime beats 100.00 % of cpp submissions.

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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;
        if(!head->next->next) return false;
        ListNode *p=head;
        ListNode *q=head->next->next;
        while(q&&q->next){
            p=p->next;
            q=q->next->next;
            if(!q) return false;
            if(p==q) return true;
        }
        return false;
    }
};


