//find out the last parent of A which is not an ancestor of B
// OR
//find out the last parent of B which is not an ancestor of A

class BinaryLifting
{
public:
    int timer;
    int l;
    vector<int> tin, tout;
    vector<vector<int>> parent;
    vector<vector<int>> adj;

    BinaryLifting(int root, int n, vector<vector<int>> &adj)
    {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        this->adj = adj;
        l = ceil(log2(n));
        parent.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        parent[v][0] = p;
        for (int i = 1; i <= l; ++i)
            parent[v][i] = parent[parent[v][i - 1]][i - 1];

        for (int u : adj[v])
        {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i)
        {
            if (!is_ancestor(parent[u][i], v))
                u = parent[u][i];
        }
        return parent[u][0];
    }
};
