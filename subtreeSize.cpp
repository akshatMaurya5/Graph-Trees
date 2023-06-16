#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll node, vector<vector<int>>&adj, int par, vector<int>&subtree)
{
    for (auto &child : adj[node])
    {
        if (child != par)
        {
            dfs(child, adj, node, subtree);
            subtree[node]+=subtree[child];
        }
    }
    subtree[node]++;
}

ll dfs1(ll node, vector<vector<int>> &adj, int par, vector<int> &subtree)
{
    for (auto &child : adj[node])
    {
        if (child != par)
        {
           subtree[node]+=dfs1(child, adj, node, subtree);
        }
    }

    subtree[node]++;
  
    return subtree[node]; 
}
vector<int>adj[1e5];
void dfs2(int u, int parent, vector<int>&size)
{
    size[u] = 1;
    for (int v : adj[u])
    {
        if (v != parent)
        {
           dfs2(v, u, size);
           size[u] += size[v];
        }
    }
}

int main() {

return 0;
}