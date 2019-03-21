/** Description
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        iteration(nestedList);
    }
    //递归调用函数，生成初始化队列
    void iteration(vector<NestedInteger> &nestedList)
    {
         for(auto list:nestedList)
         {
            if(list.isInteger())
            {
                nums.push(list.getInteger());
            }
            else
            {
                iteration(list.getList());
            }
        }
    }
    int next() 
    {
        int result =nums.front(); 
        nums.pop();
        return result;
    }
    bool hasNext() 
    {
      return !(nums.empty());
    }
private:
    //存放数据的队列
    queue<int> nums;
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
/**
 总结：vector的遍历方式
	1、C语言写法 for (int i = 0; i < nestedList.size();i++)
	2、for循环迭代器for(vector<int>::cons_itreator iter = nestedList.cbegin();iter != nestedList.cend;iter++)
	3、for循环迭代器变种for(auto iter = nestedList.cbegin();iter != nestedList.cend;iter++ )
	4、for_each+函数 for_each(nestedList.cbegin(),nestedList.cend();printer<int>)
		template<typename T>
		void printer(const T& val)
		{
			cout << val << endl;
		}
	5、for_each+lambda for_each(nestedList.cbegin(), nestedList.cend(), [](const int& val)->void{cout << val << endl; });
	6、for 区间遍历 for(auto lsit:nestedList){ cout << val << endl;}
 */