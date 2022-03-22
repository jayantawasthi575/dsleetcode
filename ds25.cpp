class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                pos.push_back(i);
        }
        int i=0;
        while(i<pos.size()/2)
        {
            char temp=s[pos[i]];
            s[pos[i]]=s[pos[pos.size()-i-1]];
            s[pos[pos.size()-i-1]]=temp;
            i++;
            //cout<<temp<<" "<<s[pos[pos.size()-i-1]]<<endl;
        }
        return s;
    }
};