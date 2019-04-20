/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。
*/

#include<string>
#include<iostream>
 #include<algorithm>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string copy =num;
        if(k==0)
            return num;
        if(k==num.size())
            return "0";
        string result="";
        string temp="";
        int p=0,len=num.size();
        for(int i=0;i<len-k;i++){
			//每次取合法范围字符中的最小值
            temp=findMin(num,p,k+i);
             p= num.find(temp,p)+1;
            if(temp=="0"&& result==""){
                continue;
            }
            result=result+temp;  
            }
            return result==""?"0":result; 
            }
    string findMin(string sub,int s,int e){
         if(sub.size()==0)
            return sub;
        char t=sub[s];
        for(;s<e;s++){
            if(sub[s+1]<t){
                t=sub[s+1];
            }
        }
        string r(1,t);
            return r;
        }
                         
};