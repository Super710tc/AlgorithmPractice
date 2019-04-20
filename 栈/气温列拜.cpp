/*根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 每个气温的值都是[30, 100], 可以考虑hash
        unordered_map<int, vector<int>> intMap;
        int max_T = 0;
        for(int i=0; i<T.size(); i++){
            intMap[T[i]].push_back(i);
            max_T = max(max_T, T[i]);
        }
        
        // 复杂度O(n*70)
        for(int i=0; i<T.size(); i++){
            int res = 0x7fffffff;
            for(int j=T[i]+1; j<=max_T; j++){ // j表示高于它的温度
                if(intMap.find(j)==intMap.end()) continue;
                auto ite = lower_bound(intMap[j].begin(), intMap[j].end(), i+1);
                if(ite!=intMap[j].end()){
                    res = min(res, (*ite)-i);
                }
            }
            if(res==0x7fffffff) T[i] = 0;
            else T[i] = res;
        }
        
        return T;
    }
};