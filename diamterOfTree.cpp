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

    ll Y=0;

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
            Z=i;
        }
    }

    cout<<distY[Z]<<endl;

    return 0;
}