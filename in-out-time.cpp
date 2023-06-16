#include<bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i=a; i<b; i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll; 
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
typedef pair<int,int> pii;

map<int, int> in, out;
vvi adj;

void dfs(ll node, ll &time, ll par)
{
    in[node] = time++;

    for (auto &it : adj[node])
    {
        if (it != par)
        {
            dfs(it, time, node);
        }
    }

    out[node] = time++;
}

void solve()
{
    ll n;
    cin >> n;
    adj.resize(n + 1);

    f(i, 1, n)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll time = 0;
    dfs(1, time, -1);

    // deb(in);
    // deb(out);
}

int main() {

return 0;
}