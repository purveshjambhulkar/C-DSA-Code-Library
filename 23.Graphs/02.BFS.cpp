void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;


    while(!q.empty()){
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();


        for(auto i: adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }   
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    vector<bool> visited(n,0);


    // traverse all components of disconnected graph
    bfs(adj, visited, ans, 0);


    return ans;
}