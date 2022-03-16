class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> t;
        string word="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                t.push_back(word);
                word="";
            }
            else{
                word=word+s[i];
            }
        }
        t.push_back(word);
        if(pattern.length()!=t.size())
        {
            return false;
        }
        // for(int i=0;i<t.size();i++)
        //     cout<<t[i]<<endl;
        s=pattern;
        unordered_map<char,string> first;
        unordered_map<string,bool> second;
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