#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

// BRUTE FORCE
//  int getKthAncestor(int node, int k,, vector<int>&par)
//  {

//     while (k--)
//     {
//         node = par[node];
//         if (node == -1)
//         {
//             break;
//         }
//     }

//     return node;
// }

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

int kthParent(int node, int k, vector<vector<int>> &parent)
{
    int ans = -1;
    int n = parent[0].size();

    for (int i = 0; i <= log2(n); i++)
    {
        if (k & (1 << i)) // ith bit set?
        {
            node = parent[i][node];

            if (node == -1)
            {
                break;
            }
        }
    }
    return node;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif

    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //[k][i] -> kth parent of node i
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n, -1));

    // find the first parent of every node
    dfs(0, -1, adj, parents[0]);

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
