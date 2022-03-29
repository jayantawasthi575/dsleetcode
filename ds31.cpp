class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> str;
        unordered_map<char,string> mp;
        if(digits.size()==0)
            return str;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string st="";
        backtrack(digits,0,mp,st,str);
        return str;
}
    void backtrack(string digits,int i,unordered_map<char,string> mp,
                  string st,vector<string>& str)
    {
        if(i==digits.size())
        {
            //cout<<st<<" ";
            str.push_back(st);
            return;
        }
        string curr=mp[digits[i]];
        string tp=st;
        for(int k=0;k<curr.length();k++)
        {
            st=st+curr[k];
            backtrack(digits,i+1,mp,st,str);
            st=tp;
        }
    }
};