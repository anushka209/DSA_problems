class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];     // node, time
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;      //store time
        priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;  // time, node
        pq.push({0,k});

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int node=it.second;

            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int time=it.second;

                if(t+time<dist[adjNode])
                {
                    dist[adjNode]=t+time;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            maxi=max(maxi,dist[i]);
        }
    return maxi;
    }
};