#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//��һ��˼·����vector��ʵ����Щ����ע��vector��ĩβ��Ӻ�ɾ����
//���Կ�����ʹ��vector��������ʱ����������
//Runtime: 76 ms, faster than 8.68% of C++ online submissions for Min Stack.
//��������ķ�������Ҫֱ�Ӷ���һ��stack��Ȼ����push��pop��ʱ����min�����⣬����getmin����ֱ�ӷ��ؼ��ɡ�

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
