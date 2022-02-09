class Solution {
public:
    void df(int node,vector<int>& vis,vector<int> adj[],vector<int> &dfs)
    {
        dfs.push_back(node);
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                df(it,vis,adj,dfs);
            }
        }
    } 
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> adj[quiet.size()];
        for(int i=0;i<richer.size();i++)
        {
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> rslt;
        for(int i=0;i<quiet.size();i++)
        {
          vector<int> dfs;
          int V=quiet.size();
          vector<int> vis(V,0);
          df(i,vis,adj,dfs);
          int min=i;
          for(int j=0;j<dfs.size();j++)
          {
              if(quiet[min]>quiet[dfs[j]])
              {
                  min=dfs[j];
              }
          }
          rslt.push_back(min);
        }
        return rslt;
    }
};