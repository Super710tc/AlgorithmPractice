/*
 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。
*/
struct P{
    int c;
    int count;
    P(){c=0; count=0;}
    P(int c, int count){
        this->c = c;
        this->count = count;
    }
    bool operator>(const P &x) const{
        return this->count > x.count;
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        if(S.length()<=1) return S;
        
 
        map<char, int> charMap;
        for(int i=0; i<S.length(); i++){
            charMap[S[i]]++;
        }
        vector<P> arr(0);
        int max_val = 0;
        for(auto ite=charMap.begin(); ite!=charMap.end(); ite++){
            arr.push_back(P(ite->first, ite->second));
            max_val = max(max_val, ite->second);
        }
        if(max_val>ceil(S.length()/2.0)) return "";
        
        sort(arr.begin(), arr.end(), greater<P>());
        S[0] = arr[0].c; arr[0].count--;
        int i=1;
        while(i<S.length()){
            sort(arr.begin(), arr.end(), greater<P>());
            if(S[i-1]!=arr[0].c){
                S[i] = arr[0].c; 
                if(i+1<S.length()) S[i+1]=arr[1].c;
            }
            else{
                S[i] = arr[1].c; 
                if(i+1<S.length()) S[i+1]=arr[0].c;
            }
            arr[0].count--; arr[1].count--; 
            i += 2;
        }
        
        return S;
    }
};