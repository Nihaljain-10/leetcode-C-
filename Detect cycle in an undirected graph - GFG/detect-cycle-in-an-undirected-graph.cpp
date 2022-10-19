//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCycleUtil(int v, bool visited[], int parent, vector<int> adj[]) {
  visited[v] = true;
  vector<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      if (isCycleUtil(*i, visited, v, adj)) {
        return true;
      }
    } else if (*i != parent) {
      return true;
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
  }
  for (int u = 0; u < V; u++) {
    if (!visited[u]) {
      if (isCycleUtil(u, visited, -1, adj)) {
        return true;
      }
    }
  }
  return false;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends