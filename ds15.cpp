class Solution {
public:
    bool isValid(string s) {
        stack<char> sp;
        if(s[0]=='('||s[0]=='['||s[0]=='{')
        {
            sp.push(s[0]);
        }
        else
        {
            return false;
        }
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {  
                sp.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!sp.empty()&&sp.top()=='(')
                {
                    sp.pop();
                }
                else
                return false;
            }
            else if(s[i]=='}')
            {
                if(!sp.empty()&&sp.top()=='{')
                {
                    sp.pop();
                }
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(!sp.empty()&&sp.top()=='[')
                    sp.pop();
                else 
                    return false;
            }
        }
        if(sp.size()==0)
        return true;
        else
            return false;
    }
};