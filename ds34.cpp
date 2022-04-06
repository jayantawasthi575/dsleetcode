class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> mp;
        unordered_map<string,vector<string>> up;
        for(auto x:strs)
        {
            string temp=x;
            sort(x.begin(),x.end());
            up[x].push_back(temp);
        }
        for(auto x:up)
        {
            mp.push_back(x.second);
        }
        return mp;   
    }
};