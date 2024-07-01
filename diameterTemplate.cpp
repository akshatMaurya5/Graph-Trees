int findTreeDiameter(vector<vector<int>>& connections) {
    int nodes = connections.size() + 1;
    if (nodes == 0) return 0;

    vector<vector<int>> graph(nodes);
    for (auto &edge: connections) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int maxDistance = 0, farthest = 0;
    
    auto dfs = [&](int start, int parent, vector<vector<int>>& adj, int distance, auto& dfs_ref) -> void {
        if (distance > maxDistance) {
            maxDistance = distance;
            farthest = start;
        }
        for (int neighbor: adj[start]) {
            if (neighbor != parent) {
                dfs_ref(neighbor, start, adj, distance + 1, dfs_ref);
            }
        }
    };

    dfs(0, -1, graph, 0, dfs);

    maxDistance = 0;
    dfs(farthest, -1, graph, 0, dfs);

    return maxDistance;
}
