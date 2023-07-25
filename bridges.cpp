#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;

//tin -> time of insertion
//low -> min lowest time of insertion of all adj nodes apart from parent
//low is basically lowest time of insertion

class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<int> vis;
    vector<vector<int>> ans;
    int time = 1;

    // we check for low for bridge when dfs of a node gets completed

    void dfs(int node, int par)
    {
        vis[node] = 1;
        tin[node] = low[node] = time++;

        for (auto &it : adj[node])
        {
            if (it == par)
                continue;

            if (!vis[it])
            {
                // do dfs and then first update low and then check for bridge for node not child

                dfs(it, node);

                low[node] = min(low[node], low[it]);

                // condn for bridge
                if (low[it] > tin[node])
                {
                    vector<int> v = {it, node};
                    ans.push_back(v);
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vis.resize(n);
        tin.resize(n);
        low.resize(n);

        adj.resize(n);

        for (auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0, -1);

        return ans;
    }
};

int main() {

return 0;
}