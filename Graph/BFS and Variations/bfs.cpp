#include <bits/stdc++.h>
using namespace std;

#define     rep(i,k,n)      for(long long int i=k;i<n;i++)
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)

const int MAXN = 107;

vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int dist[MAXN];

int N, E;

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        adj[i].clear();
        visited[i] = false;
        parent[i] = -1;
        dist[i] = 0;
    }
}

void bfs(int src)
{
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    visited[src] = true;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
}

vector<int> path(int des)
{
    vector<int> v;
    int cur = des;
    while(cur != -1)
    {
        v.push_back(cur);
        cur = parent[cur];
    }
    reverse(v.begin(), v.end());
    return v;
}

void printPath(int des)
{
    vector<int> v = path(des);
    if(v.size()>1)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    else
        cout << "No Path" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    fast;
    init();
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src = 0;
    bfs(src);
    int des = 5;
    printPath(des);
    return 0;
}

/*
complexity: O(V+E)
input: (https://media.geeksforgeeks.org/wp-content/uploads/binary-Graph.png)
8 14
0 1
1 2
2 3
2 5
3 4
3 5
4 5
5 6
6 7
6 8
7 8
7 1
7 0
8 2
output:
0 1 2 5 
*/