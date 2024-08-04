#include <list>
#include <queue>
#include <unordered_map>
#include <vector>

// APPROACH 2 - USING KAHN'S ALGORITHM

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;  // Adjusting to 0-based index
        int v = edges[i].second - 1; // Adjusting to 0-based index

        adj[u].push_back(v);
    }

    // Finding all indegrees
    vector<int> indegrees(n, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegrees[j]++;
        }
    }

    // Push all nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS
    int cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Increment count of visited nodes
        cnt++;

        // Decrement indegree of neighbours
        for (auto neighbour : adj[front]) {
            indegrees[neighbour]--;
            if (indegrees[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // If the count of visited nodes is equal to the number of nodes, no cycle
    return cnt != n;
}