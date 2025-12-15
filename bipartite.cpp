#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>constructadj(int v,vector<vector<int>>&edges)
{
    vector<vector<int>>adj(v);

    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;

}

bool isbipartite(int v,vector<vector<int>>&edges)
{
    vector<int>color(v,-1);
    vector<vector<int>>adj=constructadj(v,edges);
    queue<int>q;

    for(int i=0;i<v;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                
                for(auto &v:adj[u])
                {
                    if(color[v]==-1)
                    {
                        color[v]=1-color[u];
                        q.push(v);
                    }
                    else
                    if(color[v]==color[u])
                    return false;
                }
            }
        }        
    }
    return true;
}

int main()
{
    int v=4;

    vector<vector<int>>edges={{0,1},{0,2},{1,2},{2,3}};

    if(isbipartite(v,edges))
    cout<<"true";
    else
    cout<<"false";

    return 0;
}