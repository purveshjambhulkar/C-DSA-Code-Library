#include <bits/stdc++.h>
using namespace std;

// APPROACH 2 - USING """KAHN's Algorithm"""
//first make the adj list then find the indegree of each v and store it
//now the vertex will 0 indegree push in queue 
//now till queue empty remove the first element and push in answer
//now decrement the indegree of its neighbour and if the indegree in 0 then push in queue




vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Finding all indegrees
    vector<int> indegrees(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegrees[j]++;
        }
    }

    // 0 indegree push in queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    // Do BFS
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Store answer
        ans.push_back(front);

        // Decrement indegree of neighbours
        for (auto neighbour : adj[front]) {
            indegrees[neighbour]--;
            if (indegrees[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

  

    return ans;
}
