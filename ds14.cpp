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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       vector<int> adj[n];
       for(int i=0;i<dislikes.size();i++)
       {
           adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
           adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
       }
       int V=n;
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