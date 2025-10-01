class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,int oldcolor,int newcolor)
    {
        int n=image.size();
        int m=image[0].size();

        ans[sr][sc]=newcolor;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for (int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol]==oldcolor&& ans[nrow][ncol]!=newcolor)
            {
                dfs(nrow,ncol,ans,image,oldcolor,newcolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int oldcolor=image[sr][sc];

        vector<vector<int>>ans=image;
        if(oldcolor==color)
        return image;

        dfs(sr,sc,ans,image,oldcolor,color);
        return ans;
        
    }
};

// store the oldcolor in one variable and do dfs traversal by four directions;