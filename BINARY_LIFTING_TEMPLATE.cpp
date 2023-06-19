class BinaryLifting {
public:
    vector<vector<int>>parents;
    int n;

    BinaryLifting(int root, int n, vector<vector<int>>&adj)
    {
        this->n = n;
        parents.resize(log2(n) + 1, vector<int>(n, -1));
        fillParents(root, adj);
    }


    void fillParents(int root, vector<vector<int>>&adj)
    {
        //marking first parents
        dfs(root, -1, adj, parents[0]);

        //marking other parents

        for (int k = 1; k <= log2(n); k++)
        {
            for (int i = 0; i < n; i++)
            {
                // parent [k][i]  -> 2^(k-1)th parent of node i

                // i -> intermeditate -> goal

                // goal = 2^k th parent of node i
                // goal = 2^(k-1) th parent of node intermediate
                // intermediate = 2^(k-1)th parent of node i

                int intermediate = parents[k - 1][i];

                if (intermediate != -1)
                {
                    parents[k][i] = parents[k - 1][intermediate];
                }
            }
        }
    }

    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &firstParent)
    {
        firstParent[node] = par;

        for (auto &it : adj[node])
        {
            if (par != it)
            {
                dfs(it, node, adj, firstParent);
            }
        }
    }


    int kthParent(int node, int k)
    {
        int ans = -1;
        int n = parents[0].size();

        for (int i = 0; i <= log2(n); i++)
        {
            if (k & (1 << i)) //ith bit set?
            {
                node = parents[i][node];

                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }

};
