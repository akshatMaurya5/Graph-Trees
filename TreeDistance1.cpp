/*
Idea is from any node if we do dfs we end on an endpoint of a tree.

so find diameter of a tree by prev algo ie Dist b/w Y and Z

dist max dist from any node will be either from Y or Z
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

void dfs(ll node, ll par, vector<ll> &dist)
{
    if (par != -1)
    {
        dist[node] = dist[par] + 1;
    }
    else
    {
        dist[node] = 0;
    }

    for (auto &it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node, dist);
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll X = 0;

    vector<ll> distX(n, 0);

    dfs(X, -1, distX);

    ll Y = 0;

    for (int i = 0; i < n; i++)
    {
        if (distX[i] > distX[Y])
        {
            Y = i;
        }
    }

    vector<ll> distY(n, 0);

    dfs(Y, -1, distY);

    ll Z = 0;

    for (int i = 0; i < n; i++)
    {
        if (distY[i] > distY[Z])
        {
            Z = i;
        }
    }

    // diameter
    //  cout<<distY[Z];

    vector<ll> distZ(n, 0);
    dfs(Z, -1, distZ);

    vector<ll> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(max(distY[i], distZ[i]));
    }

    for (auto &it : ans)
        cout << it << " ";

    return 0;
}