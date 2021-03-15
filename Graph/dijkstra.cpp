#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 107;
const int INF = INT_MAX;


int N, E;
int adj[MAXN][MAXN];
bool vis[MAXN];
int parent[MAXN];
int dist[MAXN];

struct Node
{
    int v, distance;
    Node(int v, int distance)
    {
        this->v = v;
        this->distance = distance;
    }
};
bool operator < (const Node &a, const Node &b)
{
    if(a.distance > b.distance) return true;
    else return false;
}

void init()
{
    for(int i=0; i<MAXN; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
}
void dijstra(int src)
{
    dist[src] = 0;
    priority_queue<Node> pq;
    pq.push(Node(src, dist[src]));
 
    while(pq.size() != 0)
    {
        int u = pq.top().v;
        pq.pop();
 
        if(vis[u] == true) continue;
 
        vis[u] = true;
 
        for(int v = 0; v<N; v++)
        {
            int cost = adj[u][v];
            if(cost != 0)
            {
                if(dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                    parent[v] = u;
                    pq.push(Node(v, dist[v]));
                }
            }
        }
    }
}
void input()
{
    cin >> N >> E;
    for(int i = 0; i<E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
}
void PrintPath(int x)
{
    if(x == -1) return;
    PrintPath(parent[x]);
    cout << x << " ";
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
    init();
    input();
 
    dijstra(0);
 
    for(int i = 0; i<N; ++i) 
    {
        cout << "Node " << i << ": " << endl;
        cout << "Path : ";
        PrintPath(i);
        cout << "Distance : " << dist[i] << endl;
        cout << endl;
        cout << endl;
    }
}


/*
input image: https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10

*/
