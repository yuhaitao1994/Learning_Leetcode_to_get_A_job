#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//第一种思路，用vector，实在有些慢，注意vector从末尾添加和删除。
//可以看出，使用vector这种容器时计算会很慢。
//Runtime: 76 ms, faster than 8.68% of C++ online submissions for Min Stack.
//如果想更快的方法，需要直接定义一个stack，然后再push和pop的时候处理min的问题，这样getmin函数直接返回即可。

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    MinStack() {

    }

    void push(int x) {
        st.push_back(x);
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st[st.size()-1];
    }

    int getMin() {
        int getmin=st[0];
        for(int i=1;i<st.size();i++){
            if(st[i]<getmin)
                getmin=st[i];
        }
        return getmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
