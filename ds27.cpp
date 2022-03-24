class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> sp;
        for(int i=0;i<s.length();i++)
        {
            sp[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
            if(sp[s[i]]==1)
                return i;
        return -1;
    }
};