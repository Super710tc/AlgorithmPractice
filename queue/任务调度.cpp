/*给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的最短时间。

示例 1：

输入: tasks = ["A","A","A","B","B","B"], n = 2
输出: 8
执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size()==0) return 0;
        int hash[26]={0};
        for(int i=0;i<tasks.size();i++)
            hash[tasks[i]-'A']++;
        pair<int,int> max(0,0);
        for(int i=0;i<26;i++){
            if(hash[i]>max.first) {
                max.first=hash[i];
                max.second=1;
            }
            else if(hash[i]==max.first)
                max.second++;
        }
        int a=tasks.size()-max.first-max.second+1;
        int b=n*(max.first-1);
        int ans;
        if(a>=b)  ans=tasks.size();
        else ans=(n+1)*(max.first-1)+max.second;
        
        return ans;
        
    }
};