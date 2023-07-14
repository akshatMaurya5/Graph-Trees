
vector<vector<int>>adj;
vector<int>depth, parent;
void dfs(int node, vector<int>&vis)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            depth[it] = depth[node] + 1;
            parent[it] = node;
            dfs(it, vis);
        }
    }

}

int lca(int u, int v)
{
    if (u == v) return u;

    if (depth[u] < depth[v]) swap(u, v);

    //u at deeper level
    int diff = depth[u] - depth[v];
    while (diff--)
    {
        u = parent[u];
    }
    if (u == v) return u;

    while (parent[u] != parent[v])
    {
        u = parent[u];
        v = parent[v];
    }

    return parent[u];
}