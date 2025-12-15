class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<pair<int,int>,int>>q;
        int time=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                else
                if(grid[i][j]==1)
                fresh++;
            }
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            int row=it.first.first;
            int col=it.first.second;
            int t=it.second;\
            time=max(time,t);

            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow <n && ncol >=0 && ncol<m && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol]=2;
                    fresh--;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }

        if(fresh==0)
        return time;
        else 
        return -1;
        
    }
};