
/*给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    unordered_map<string, bool> visitedMap; // 是否已经访问过
    unordered_set<string> wordListSet(wordList.begin(), wordList.end());  // 查找表，优化速度

    queue<pair<string, int>> q; // [string, stepNum]
    q.push(make_pair(beginWord, 1));
    visitedMap[beginWord] = true;
    while (!q.empty()) {

        pair<string, int> p = q.front();
        q.pop();

        if (p.first == endWord) return p.second; // 找到

        for (int i = 0; i < p.first.size(); i++) {
            string tmp = p.first; 
            for (char c = 'a'; c <= 'z'; c++) {
                (p.first)[i] = c;
                if ( (wordListSet.find(p.first) != wordListSet.end()) && !visitedMap[p.first]) {
                    q.push(make_pair(p.first, p.second + 1));
                    visitedMap[p.first] = true;
                }
            }
            p.first = tmp;
        }
    }
    return 0;
}
};