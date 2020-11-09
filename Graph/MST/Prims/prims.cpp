#include<bits/stdc++.h>
using namespace std;

#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     ll              long long int
#define     PII             pair<int, int>

const int MAXN = 1007;
bool vis[MAXN];
vector <PII> adj[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
}


int prims(int x)
{
    int minCost = 0;
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        PII p = Q.top();
        Q.pop();
        int cost = p.first;
        int u = p.second;
        if(vis[u]) continue;
        minCost += cost;
        vis[u] = true;
        for(int i = 0;i < adj[u].size();++i)
        {
            int v = adj[u][i].second;
            if(!vis[v])
                Q.push(adj[u][i]);
        }
    }
    return minCost;
}

int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    init();
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(weight, v));
        adj[v].push_back(make_pair(weight, u));
    }
    int minimumCost = prims(1);
    cout << minimumCost << endl;
    return 0;   
}

/*
complexity: O((V+E)logV)
input:
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
output:
19
*/