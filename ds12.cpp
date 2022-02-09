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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> adj[rooms.size()];
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        int V=rooms.size();
        vector<int> dfs;
        vector<int> vis(V,0);
        df(0,vis,adj,dfs);
        if(dfs.size()==rooms.size())
            return true;
        return false;
    }
};