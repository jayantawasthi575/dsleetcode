class Solution {
public:
    bool bipartiteDfs(int node,vector<int> adj[],int color[])
    {
        if(color[node]==-1)
        color[node]=1;
        for(auto it:adj[node])
        {
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!bipartiteDfs(it,adj,color))
                {
                    return false;
                }
            }
            else if(color[it]==color[node])
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> adj[graph.size()];
       for(int i=0;i<graph.size();i++)
       {
           for(int j=0;j<graph[i].size();j++)
           adj[i].push_back(graph[i][j]);
           
       }
	    int V=graph.size();
	    int color[V];
	    memset(color,-1,sizeof color);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!bipartiteDfs(i,adj,color))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
};