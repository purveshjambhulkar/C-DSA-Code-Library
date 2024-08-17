vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    vector<int> answer;

    vector<int> distance(n+1, 1e8);

 

    distance[src] = 0;  

    for(int i=1;i<n;i++){

      for (int j = 0; j < m; j++) {

        if ((distance[edges[j][0]] + edges[j][2]) < distance[edges[j][1]])

          distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
      }
    }

    return distance;
}