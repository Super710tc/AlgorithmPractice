给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size()==0){
            return result;
        }
        //按start升序排序
        sort(intervals.begin(),intervals.end(),[](Interval&a,Interval&b){return a.start<b.start;});
        Interval temp =intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(temp.end>=intervals[i].start&&temp.end<=intervals[i].end){
                temp.end=intervals[i].end;
            }else if(temp.end>intervals[i].start&&temp.end>intervals[i].end){
                continue;
            }else{
                result.push_back(temp);
                temp=intervals[i];
            }
        }
         result.push_back(temp);
        
        return result;
    }
};