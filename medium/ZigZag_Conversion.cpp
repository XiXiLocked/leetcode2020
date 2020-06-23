//6. ZigZag Conversion
// 思路是找规律
// 可以分成一段一段的. 从0下去,回来到4,4和0之后到方向是重复的
// 没有一次AC的原因,变量名写错了.
class Solution {
public:
    string convert(string s, int numRows) {
        // 0   4   8      12
        // 1 3 5 7 9   11 
        // 2   6   10
        
        if (numRows==0)
        {
            return "";
        }
        if (numRows==1)
        {
            return s;
        }
        string t = string(s.length(), ' ' );
        int j = 0;
        int sp = 2*numRows-2;
        //  row 0
        for (int i =0;i<s.length();i+=sp)
        {
            t[j++] = s[i];
        }
        // row 1~n-2
            
        for(int r=1;r<numRows-1;++r)
        {
            for (int i=0;i<s.length();i+=sp)
            {
                if (i+r<s.length())
                {
                    t[j++] = s[i+r];
                }
                if (i+sp-r <s.length())
                {
                    t[j++] = s[i+sp-r];
                }
            }
        }
        // last row
        for (int i =numRows-1;i<s.length();i+=sp)
        {
            t[j++] = s[i];
        }
        return t;
        
    }
};