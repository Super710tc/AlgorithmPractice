/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。*/
class Solution {
public:
    bool isValid(string s) {
        stack <char> ans;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(ans.empty()){
                ans.push(s[i]);
            }
            else if((ans.top() == '(' && s[i] == ')')
                  || (ans.top() == '[' && s[i] == ']')
                  || (ans.top() == '{' && s[i] == '}'))
                ans.pop();
            else
                ans.push(s[i]);
        }
        return ans.empty();
    }
};