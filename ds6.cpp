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
    void findTopoSort(int node,vector<int>& vis,stack<int>& st,vector<int> adj[])
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        findTopoSort(it,vis,st,adj);
	    }
	    st.push(node);
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int vis[numCourses],dfsVis[numCourses];
        memset(vis,0,sizeof vis);
        memset(dfsVis,0,sizeof dfsVis);
        vector<int> topo;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i,adj,vis,dfsVis))
                    return topo;
            }
        }
        stack<int> st;
	    vector<int> vi(numCourses,0);
	    for(int i=0;i<numCourses;i++)
        {
            if(vi[i]==0)
            findTopoSort(i,vi,st,adj);
        }
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};