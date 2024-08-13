class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;    // {diff,{row,col}}
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1)  return diff;
            for(int i=0;i<4;i++)
            {
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newEffort=max(abs(heights[r][c]-heights[newr][newc]),diff);
                    if(newEffort<dist[newr][newc])
                    {
                        dist[newr][newc]=newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};