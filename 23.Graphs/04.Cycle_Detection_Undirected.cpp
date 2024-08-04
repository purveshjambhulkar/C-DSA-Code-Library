#include <list>
#include <queue>
#include <unordered_map>

// bool isCyclic(int node ,unordered_map<int  , bool> &visited ,
// unordered_map<int , list<int>> &adj ){

//     unordered_map<int , int> parent;
//     parent[node] = -1;
//     visited[node] = 1;
//     queue<int> q;
//     q.push(node);
//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto neighbour : adj[front]){
//             if(visited[neighbour] == true && neighbour != parent[front]){
//                 return true;
//             }else if(!visited[neighbour]){
//                 q.push(neighbour);
//                 visited[neighbour] = 1;
//                 parent[neighbour] = front;
//             }
//         }

//     }

//     return false;
//  }

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {
  visited[node] = true;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      bool isCycle = isCyclicDFS(neighbour, node, visited, adj);
      if (isCycle) {
        return true;
      }else if(neighbour != parent){
          return true;
      }
    }
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  // Write your code here.

  // create a adj list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // to handle disconnected component

  unordered_map<int, bool> visited;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool ans = isCyclicDFS(i, -1, visited, adj);
      if (ans == true) {
        return "Yes";
      }
    }
  }

  return "No";
}
