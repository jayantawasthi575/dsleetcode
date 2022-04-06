class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        vector<int> str(num1.length()+num2.length(),0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.length();i++)
            for(int j=0;j<num2.length();j++)
            {
                int digit=(num1[i]-'0')*(num2[j]-'0');
                str[i+j]=str[i+j]+digit;
                str[i+j+1]=str[i+j+1]+str[i+j]/10;
                str[i+j]=str[i+j]%10;
            }
        string ans="";
        int j=str.size()-1;
        while(j>=0)
        {
        if(str[j]==0)
            j--;
        else
            break;
        }
        for(int i=0;i<=j;i++)
            ans=ans+to_string(str[i]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};