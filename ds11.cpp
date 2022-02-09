class Solution {
public:
    bool checkCycle(int node,vector<int> adj[],int vis[],int dfsVis[])
    {
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it,adj,vis,dfsVis))
                    return true;
            }
            else if(dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        int V=graph.size();
        int vis[V],dfsVis[V];
        memset(vis,0,sizeof vis);
        memset(dfsVis,0,sizeof dfsVis);
        vector<int> dfs;
        for(int i=0;i<V;i++)
        {
           if(checkCycle(i,adj,vis,dfsVis))
           {
               memset(vis,0,sizeof vis);
               memset(dfsVis,0,sizeof dfsVis);
           }
           else
           {
             memset(vis,0,sizeof vis);
             memset(dfsVis,0,sizeof dfsVis);  
             dfs.push_back(i);
           }
        }
        return dfs;
    }
};