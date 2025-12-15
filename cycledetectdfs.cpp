#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited)) return true;
            }
            else if (neighbor != parent) {
                // visited & not parent → cycle
                return true;
            }
        }
        return false;
    }
    
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        vector<int> visited(V, 0);
        vector<vector<int>> adj = constructadj(V, edges);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> edges;
    cout << "Enter edges (u v) one per line (0-based indexing):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    Solution sol;
    if (sol.isCycle(V, edges)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle in the graph.\n";
    }
    return 0;
}