/**
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
*/


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> charStake;
        string result,temp;
        //使用串流处理字符串分割
        stringstream ps(path);
        while(getline(ps,temp,'/')){
            if(temp=="."||temp=="")
                continue;
            else if(temp==".."){
                if(!charStake.empty())
                    charStake.pop_back();
                else
                    continue;
            }
            else
                charStake.push_back(temp);
        }
        for(const auto s :charStake){
            result+="/"+s;
        }
       return charStake.empty()?"/":result;
    }
  
};Stake.empty()?"/":result;
    }
  
};