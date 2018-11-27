#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

//自己想的异或的思路不对，用到了别人的思路。不求顺序，就看两个串中各字符出现次数是不是一样多即可。
//所以定义两个vector容器，大小都是26，存储两个串各字符出现的次数，然后不断遍历比较。
//Runtime: 28 ms, faster than 62.34% of C++ online submissions for Find All Anagrams in a String.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(26,0), pv(26,0), output;
        if(s.length()<p.length()) return output;
        for(int i=0;i<p.length();i++){
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        if(sv==pv) output.push_back(0);
        for(int i=p.length();i<s.length();i++){
            sv[s[i-p.length()]-'a']--;
            sv[s[i]-'a']++;
            if(sv==pv) output.push_back(i-p.length()+1);
        }
        return output;
    }
};

int main()
{
    string s="cbaebabacd";
    string p="cba";
    Solution so;
    vector<int> b=so.findAnagrams(s,p);
    for(int i=0;i<b.size();i++)
        cout<<b[i];
    system("pause");
}
