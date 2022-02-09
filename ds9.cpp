class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            vector<int> t1;
            t1.push_back(times[i][1]);
            t1.push_back(times[i][2]);
            adj[times[i][0]].push_back(t1);
        }
        int V=n,S=k;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> distTo(V+1,INT_MAX);
        distTo[S]=0;
        pq.push(make_pair(0,S));
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            vector<pair<int,int>>:: iterator it;
            for(auto it:adj[prev])
            {
                int next=it[0];
                int nextDist=it[1];
                if(distTo[next]>dist+nextDist)
                {
                    distTo[next]=distTo[prev]+nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
        int max=-1;
        for(int i=1;i<=V;i++)
        {
            if(distTo[i]==INT_MAX)
                return -1;
            else if(distTo[i]>max)
                max=distTo[i];
        }
        return max;
    }
};