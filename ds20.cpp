class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' '&&iswalnum(s[i]))
            {
                //cout<<s[i];
                str.push_back(char(tolower(s[i])));
            }
        }
        int i=0,j=str.size()-1;
        while(j>=i)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};