/*
 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
		//根据第一个数降序排序，第一个数相等，更加第二个数升序排序
       sort(people.begin(),people.end(),[](pair<int, int> a,pair<int, int> b){
           return a.first > b.first || (a.first == b.first && a.second < b.second);});
        for (auto p : people) {
        result.insert(result.begin() + p.second, p);
    }
    return result;
    }
};