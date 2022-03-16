class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> first;
        unordered_map<char,bool> second;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(first.find(s[i])==first.end())
            {
               if(second[t[i]]==true)
                   return false;
               else
               {
                   first[s[i]]=t[i];
                   second[t[i]]=true;
               }
            }
            else
            {
                if(first[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};