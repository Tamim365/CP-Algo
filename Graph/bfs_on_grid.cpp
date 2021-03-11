/*
    * NxM Grid
    * left-top(0,0), right corner(N-1, M-1)
    * 0 -> obstacle, 1-> free
*/

#include<bits/stdc++.h>
using namespace std;

#define     fast            ios_base::sync_with_stdio(false)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     ALL(p)          p.begin(),p.end()
#define     CLR(p)          memset(p, 0, sizeof(p))
#define     MEM(a, b)       memset(a, (b), sizeof(a))
#define     ff 	            first
#define     ss 	            second
#define     PII             pair<int, int>
#define     ll              long long int

int fx4[] = {0, 0, -1, +1};
int fy4[] = {+1, -1, 0, 0};
int fx8[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int fy8[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int fx8Knight[] = {+2, +2, +1, -1, -2, -2, -1, +1};
int fy8Knight[] = {+1, -1, -2, -2, -1, +1, +2, +2};

const int MAXN = 107;

int adj[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
PII parent[MAXN][MAXN];

int N, M;

void init()
{
    CLR(adj);
    CLR(vis);
    CLR(dist);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            parent[i][j] = {-1, -1};
}

void bfs(PII src)
{
    queue<PII> q;
    q.push(src);
    vis[src.ff][src.ss] = true;
    dist[src.ff][src.ss] = 0;
    while(!q.empty())
    {
        int ux = q.front().ff;
        int uy = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + fx4[i];
            int vy = uy + fy4[i];
            if(vx >= 0 && vx < N && vy >= 0 && vy < M && adj[vx][vy] != 0)
            {
                if(!vis[vx][vy])
                {
                    vis[vx][vy] = true;
                    dist[vx][vy] = dist[ux][uy] + 1;
                    parent[vx][vy] = {ux, uy};
                    q.push({vx, vy});
                }
            }
        }
    }
}

vector<PII> path(PII des)
{
    vector<PII> v;
    PII cur = des;
    while(cur.ff != -1 && cur.ss != -1)
    {
        v.push_back({cur.ff, cur.ss});
        cur = parent[cur.ff][cur.ss];
    }
    reverse(ALL(v));
    return v;
}

void printPath(PII des)
{
    vector<PII> v = path(des);
    if(v.size()>1)
    {
        for(auto i : v)
            cout << i.ff << ' ' << i.ss << endl;
    }
    else
        cout << "No Path" << endl;
}

void printGrid()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
            cout << adj[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    fast;
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> adj[i][j];
    PII src = {0, 0};
    PII des = {N - 1, M - 1};
    bfs(src);
    printPath(des);
    return;
}
/*
complexity: O(M*N)
input:
5 4 
1 1 1 0 
1 0 1 1
0 1 1 1 
1 1 0 1 
1 1 1 1
output:
0 0
0 1
0 2
1 2
1 3
2 3
3 3
4 3
*/

