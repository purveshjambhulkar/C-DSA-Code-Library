x   #include<unordered_map>

#include<list>

void dfs(int node, int &parent, int &timer, vector<int> &discTime, vector<int> &low, 

vector<vector<int>> &result, unordered_map<int, list<int>> &adj, vector<int> &visited){

    visited[node] = true;

    low[node] = discTime[node] = timer++;  

    for(auto neighbour:adj[node]){

        if(neighbour == parent) continue;

        if(!visited[neighbour]){

           dfs(neighbour, node, timer, discTime, low, result, adj, visited);

            low[node] = min(low[node], low[neighbour]);  

            // check if edge is bridge or not?

            if(low[neighbour] > discTime[node]){

                vector<int> temp;

                temp.push_back(node);

                temp.push_back(neighbour);

                result.push_back(temp);

            }

        }

        // node already visited and not parent

        // backedge

        else low[node] = min(low[node], discTime[neighbour]);

    }

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;

    for(int i=0;i<edges.size();i++){

        adj[edges[i][0]].push_back(edges[i][1]);

        adj[edges[i][1]].push_back(edges[i][0]);

    }

    vector<int> discTime(v, -1), low(v, -1), visited(v, false);

    int timer = 0;

    int parent = -1;

    vector<vector<int>> result;  

    for(int i=0;i<v;i++){

        if(!visited[i]){

           dfs(i, parent, timer, discTime, low, result, adj, visited);

        }

    }  

    return result;

}