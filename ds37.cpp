//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int ans = 0,len=S.size();string s=S;
   for (int i = 0; i < len; i++) {
       if (i % 2 == 0 && s[i] == '1')
           ans++;
       if (i % 2 == 1 && s[i] == '0')
           ans++;
   }
   return min(ans, len - ans);
}