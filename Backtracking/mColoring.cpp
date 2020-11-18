/*
    * colors are 0 to m-1
    * nodes are 0 to n-1
    * initially all colors are -1
*/

#include<bits/stdc++.h>
using namespace std;

#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     MEM(a, b)       memset(a, (b), sizeof(a))

const int MAXN = 107;

vector<int> adj[MAXN];
int color[MAXN];
vector<int> coloredNode;
int n, e, m;

bool isSafe(int u, int k)
{
    for(auto v : adj[u])
    {
        if(color[v] == k)
            return false;
    }
    return true;
}

void printColor()
{
    for (int i = 0; i < n; i++)
    {
        cout << color[i] << ' ';
    }
    cout << endl;
}

bool graphColor(int v)
{
    if(v == n)
    {
        printColor();
        return true;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if(isSafe(v, i))
            {
                color[v] = i;
                if(graphColor(v+1))
                    return true;
                color[v] = -1;
            }
        }
    }
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    fast;
    MEM(color, -1);
    cin >> n >> e >> m;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(!graphColor(0))
        cout << "No Solution" << endl;
    return 0;
}

/*
Complexity: O(n^m)
input:
4 5 3
0 1
1 2
0 2
2 3
0 3
output:
0 1 2 1 
*/