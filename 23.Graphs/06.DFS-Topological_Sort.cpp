#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 - using vector instead of map to solve TLE

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj,
         stack<int> &stk) {
  visited[node] = true;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      dfs(neighbour, visited, adj, stk);
    }
  }

  // Push current node to stack only after visiting all its neighbours
  stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  // Create adjacency list
  vector<vector<int>> adj(v + 1);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
  }

  // Visited map
  vector<bool> visited(v, 0);
  // Stack to store the topological order
  stack<int> stk;

  // Perform DFS for all vertices
  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      dfs(i, visited, adj, stk);
    }
  }

  // Extract elements from stack to form the topological sort order
  vector<int> ans;
  while (!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
  }

  return ans;
}
