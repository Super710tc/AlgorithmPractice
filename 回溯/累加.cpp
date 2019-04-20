/*
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true 
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true 
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
*/

public:
    bool backtracking(long long n1, long long n2, string cur_str)
    {
        if (cur_str.empty())
            return false;
        bool flag = false;
        for (int i = 1; i <= cur_str.size(); i++)
        {
            string cur_substr = cur_str.substr(0, i);

            if (cur_substr[0] == '0' && cur_substr.size() > 1)
                continue;
            long n3 = stoll(cur_substr);
            if (n1 + n2 == n3)
            {
                if (i == cur_str.size())
                    return true;
                flag = flag || backtracking(n2, n3, cur_str.substr(i, cur_str.size() - i));
                if (flag)
                    return flag;
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num)
    {
        bool flag = false;
        if (num.size() <= 2)
            return false;
        for (int i = 1; i < num.size(); i++)
        {
            for (int j = 1; j + i < num.size(); j++)
            {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j);
                if ((s1[0] == '0' && s1.size() > 1) || (s2[0] == '0' && s2.size() > 1))
                    continue;
                flag = flag || backtracking(stoll(s1), stoll(s2), num.substr(j + i, num.size() - i - j));
                if (flag)
                    return flag;
            }
        }
        return false;
    }