// 20. Valid Parentheses

// 思路 stack
// 第一次没AC, 题都没读完..只做了() [] 没做 {}

class Solution {
public:
    bool isValid(string s) {
        if (s.length()==0)
        {
            return true;
        }
        if (s.length()%2==1)
        {
            return false;
        }
        vector<char> stack;
        for (int i =0;i<s.length();++i)
        {
            switch(s[i])
            {
                case '(':
                stack.push_back('(');
                break;
                case ')':
                if (stack.empty()) { return false; }
                else
                {
                    char last = stack[stack.size()-1];
                    if (last == '(') { stack.pop_back(); }
                    else{ return false; }
                }
                break;
                case '[':
                stack.push_back('[');
                break;
                case ']':
                if (stack.empty()) { return false; }
                else
                {
                    char last = stack[stack.size()-1];
                    if (last == '[') { stack.pop_back(); }
                    else{ return false; }
                }
                break;

                case '{':
                stack.push_back('{');
                break;
                case '}':
                if (stack.empty()) { return false; }
                else
                {
                    char last = stack[stack.size()-1];
                    if (last == '{') { stack.pop_back(); }
                    else{ return false; }
                }
                break;
                default:
                return false;
            }

        }
        return stack.size()==0;
        
    }
};