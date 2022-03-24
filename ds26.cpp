class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<magazine.length();i++)
        {
            mp[magazine[i]]++;
        }
        int k=ransomNote.length();
        for(int i=0;i<ransomNote.length();i++)
        {
            if(mp.find(ransomNote[i])==mp.end())
                continue;
            cout<<ransomNote[i]<<" "<<endl;
            if(mp[ransomNote[i]]<=0)
                continue;
            mp[ransomNote[i]]--;
            k--;
        }
        if(k==0)
            return true;
        else
            return false;
    }
};