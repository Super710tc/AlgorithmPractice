/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //判断数组
        bool flag=false;
        for(auto s:nums){
            if(s!=0){
                flag = true;
                break;
            }
        }
        if(!flag) 
            return string("0"); 
        vector<string> str_nums;
        //转换成vector<string> 
        for(auto sn:nums){
            string str = to_string(sn);
            str_nums.push_back(str);
        }
        //自定义一种排序方式 比较 s1 + s2 和 s2 + s1
        sort(str_nums.begin(),str_nums.end(),
            [](string &a,string &b){return a+b >b+a?true:false;});
        string result="";
        for(auto sn:str_nums){
            result+=sn;
        }
        return result;
    }  
};