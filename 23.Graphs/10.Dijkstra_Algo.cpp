#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int edge, int source) {
  // creating adjacency list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  vector<int> dist(vertices, INT_MAX);  // Initialize distances to infinity
  set<pair<int, int>> st;

  dist[source] = 0;
  st.insert(make_pair(0, source));

  while (!st.empty()) {
    // Fetch the top pair
    auto top = *(st.begin());
    int nodeDistance = top.first;
    int topNode = top.second;

    // Remove the top record
    st.erase(st.begin());

    // Traverse the neighbors
    for (auto neighbour : adj[topNode]) {
      if (nodeDistance + neighbour.second < dist[neighbour.first]) {
        auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

        if (record != st.end()) {
          st.erase(record);
        }

        // Update the distance
        dist[neighbour.first] = nodeDistance + neighbour.second;
        st.insert(make_pair(dist[neighbour.first], neighbour.first));
      }
    }
  }

  return dist;  // Return the distances
}
