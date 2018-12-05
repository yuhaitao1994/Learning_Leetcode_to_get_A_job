#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//简单思路，当不匹配时，从haystack字符串的下一个字符重新开始。
//Runtime: 4 ms, faster than 98.62% of C++ online submissions for Implement strStr().

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int h_index=0;
        int n_index=0;
        int h_len=haystack.length();
        int n_len=needle.length();
        for(int i=0;i<h_len;i++){
            if(haystack[i]==needle[n_index]){
                n_index++;
                if(n_index==n_len) return h_index;
            }
            else{
                if(n_index==0)
                    h_index=i+1;
                else{
                    n_index=0;
                    i=h_index;
                    h_index++;
                }
            }
        }
        return -1;
    }
};

int main()
{
    string a="mississippi";
    string b="issip";
    Solution so;
    int laji=so.strStr(a,b);
    cout<<laji<<endl;
    system("pause");
}
