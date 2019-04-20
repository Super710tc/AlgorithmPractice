/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> result{""};
        if(digits.size()==0) return {};
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string str = mp[digits[i]];
            for(int j=0;j<str.size();j++){
                for(string s:result) 
                    temp.push_back(s+str[j]);
            }
            result = temp;
        }
        return result;
    }
};