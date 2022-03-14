class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle=="")
           return 0;
      int len=haystack.length()+1-needle.length(); 
      int flag=0;
      for(int i=0;i<len;i++)
      {
          if(haystack[i]==needle[0])
          {
           for(int j=0;j<needle.length();j++)
           {
               if(haystack[j+i]==needle[j])
                   flag=1;
               else 
               {flag=0;
                   break;}
               //cout<<haystack[j+i];
           }
              if(flag==1)
              return i;
          }
      }
        return -1;
    }
};