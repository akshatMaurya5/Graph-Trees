#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> scc;

void dfs1(ll node, vector<vector<ll>> &adj, vector<ll> &vis, stack<ll> &st)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, adj, vis, st);
        }
    }
    st.push(node);
}

void get_scc_nodes(ll node, vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &currScc)
{
    vis[node] = 1;
    currScc.push_back(node);

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            get_scc_nodes(it, adj, vis, currScc);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj, radj;    
    adj.resize(n + 1);
    radj.resize(n + 1);
    scc.clear();
    stack<ll> st;

    vector<ll>vis(n+1, 0);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    // to get nodes according to the finishing time
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i, adj, vis, st);
        }
    }

    // kosaraju algo start, we have to use reversed adj now

    vector<ll>vis1(n+1, 0);
    scc.clear();

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        // cout << node << endl;
        if (!vis1[node])
        {
            vector<ll>currscc;
            get_scc_nodes(node, radj, vis1, currscc);
            scc.push_back(currscc);
        }
    }

    // printing answer

    ll total_scc = scc.size();

    cout << total_scc << endl;

    vector<ll> ans(n + 1, 0);

    ll scc_cnt = 1;

    for (auto &it : scc)
    {
        // iterating over nodes in a scc
        for (auto &jt : it)
        {
            ans[jt] = scc_cnt;
        }
        scc_cnt++;
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}