/*
    * can find the shortest path from every source S for all vertices V in O(V^3).
    * weights can be negative.
    * detects negative weight cycle.
    * Initially, the size of the distance (i, i) is zero. 
    * A path [i, k…i] can only improve upon this if it has a length less than zero, i.e., denotes a negative cycle. 
    * Thus, after the algorithm, (i, i) will be negative if there exists a negative-length path from i back to i.
*/

#include<bits/stdc++.h>
using namespace std;

const int       MAXN = 107;

int N, M;
int dist[MAXN][MAXN];
int parent[MAXN][MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if(i == j) 
            {
                dist[i][j] = 0;
                parent[i][j] = 0;
            }
            else 
            {
                dist[i][j] = INT_MAX;
                parent[i][j] = -1;
            }
        }
    }
}

bool floyd_warshall()
{
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
            if(dist[i][i] < 0) return false;
        }
    }
    return true;
}

void path(int u, int v)
{
    if(parent[u][v] == u)
    {
        printf("%d, ", u);
        return;
    }
    path(u, parent[u][v]);
    printf("%d, ", parent[u][v]);
}

/*
    In case of real weights:
    if (dist[i][k] + dist[k][j] < dist[i][j] - EPS)
        dist[i][j] = dist[i][k] + dist[k][j];
*/



signed main() {
    init();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
        parent[u][v] = u;
        parent[v][u] = v;
    }
    bool hasNegCycle = true;
    if(floyd_warshall()) hasNegCycle = false;
    if(hasNegCycle) cout << "The graph contains Neg Cycle\n";
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("Distance from %d to %d is : %d ", i, j, dist[i][j]);
                printf(" [");
                if(i != j) path(i, j);
                printf("%d]\n", j);
            }
        }
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

Output:
Distance from 0 to 0 is : 0  [0]
Distance from 0 to 1 is : 4  [0, 1]
Distance from 0 to 2 is : 12  [0, 1, 2]
Distance from 0 to 3 is : 19  [0, 1, 2, 3]
Distance from 0 to 4 is : 21  [0, 7, 6, 5, 4]
Distance from 0 to 5 is : 11  [0, 7, 6, 5]
Distance from 0 to 6 is : 9  [0, 7, 6]
Distance from 0 to 7 is : 8  [0, 7]
Distance from 0 to 8 is : 14  [0, 1, 2, 8]
Distance from 1 to 0 is : 4  [1, 0]
Distance from 1 to 1 is : 0  [1]
Distance from 1 to 2 is : 8  [1, 2]
Distance from 1 to 3 is : 15  [1, 2, 3]
Distance from 1 to 4 is : 22  [1, 2, 5, 4]
Distance from 1 to 5 is : 12  [1, 2, 5]
Distance from 1 to 6 is : 12  [1, 7, 6]
Distance from 1 to 7 is : 11  [1, 7]
Distance from 1 to 8 is : 10  [1, 2, 8]
Distance from 2 to 0 is : 12  [2, 1, 0]
Distance from 2 to 1 is : 8  [2, 1]
Distance from 2 to 2 is : 0  [2]
Distance from 2 to 3 is : 7  [2, 3]
Distance from 2 to 4 is : 14  [2, 5, 4]
Distance from 2 to 5 is : 4  [2, 5]
Distance from 2 to 6 is : 6  [2, 5, 6]
Distance from 2 to 7 is : 7  [2, 5, 6, 7]
Distance from 2 to 8 is : 2  [2, 8]
Distance from 3 to 0 is : 19  [3, 2, 1, 0]
Distance from 3 to 1 is : 15  [3, 2, 1]
Distance from 3 to 2 is : 7  [3, 2]
Distance from 3 to 3 is : 0  [3]
Distance from 3 to 4 is : 9  [3, 4]
Distance from 3 to 5 is : 11  [3, 2, 5]
Distance from 3 to 6 is : 13  [3, 2, 5, 6]
Distance from 3 to 7 is : 14  [3, 2, 5, 6, 7]
Distance from 3 to 8 is : 9  [3, 2, 8]
Distance from 4 to 0 is : 21  [4, 5, 6, 7, 0]
Distance from 4 to 1 is : 22  [4, 5, 2, 1]
Distance from 4 to 2 is : 14  [4, 5, 2]
Distance from 4 to 3 is : 9  [4, 3]
Distance from 4 to 4 is : 0  [4]
Distance from 4 to 5 is : 10  [4, 5]
Distance from 4 to 6 is : 12  [4, 5, 6]
Distance from 4 to 7 is : 13  [4, 5, 6, 7]
Distance from 4 to 8 is : 16  [4, 5, 2, 8]
Distance from 5 to 0 is : 11  [5, 6, 7, 0]
Distance from 5 to 1 is : 12  [5, 2, 1]
Distance from 5 to 2 is : 4  [5, 2]
Distance from 5 to 3 is : 11  [5, 2, 3]
Distance from 5 to 4 is : 10  [5, 4]
Distance from 5 to 5 is : 0  [5]
Distance from 5 to 6 is : 2  [5, 6]
Distance from 5 to 7 is : 3  [5, 6, 7]
Distance from 5 to 8 is : 6  [5, 2, 8]
Distance from 6 to 0 is : 9  [6, 7, 0]
Distance from 6 to 1 is : 12  [6, 7, 1]
Distance from 6 to 2 is : 6  [6, 5, 2]
Distance from 6 to 3 is : 13  [6, 5, 2, 3]
Distance from 6 to 4 is : 12  [6, 5, 4]
Distance from 6 to 5 is : 2  [6, 5]
Distance from 6 to 6 is : 0  [6]
Distance from 6 to 7 is : 1  [6, 7]
Distance from 6 to 8 is : 6  [6, 8]
Distance from 7 to 0 is : 8  [7, 0]
Distance from 7 to 1 is : 11  [7, 1]
Distance from 7 to 2 is : 7  [7, 6, 5, 2]
Distance from 7 to 3 is : 14  [7, 6, 5, 2, 3]
Distance from 7 to 4 is : 13  [7, 6, 5, 4]
Distance from 7 to 5 is : 3  [7, 6, 5]
Distance from 7 to 6 is : 1  [7, 6]
Distance from 7 to 7 is : 0  [7]
Distance from 7 to 8 is : 7  [7, 8]
Distance from 8 to 0 is : 14  [8, 2, 1, 0]
Distance from 8 to 1 is : 10  [8, 2, 1]
Distance from 8 to 2 is : 2  [8, 2]
Distance from 8 to 3 is : 9  [8, 2, 3]
Distance from 8 to 4 is : 16  [8, 2, 5, 4]
Distance from 8 to 5 is : 6  [8, 2, 5]
Distance from 8 to 6 is : 6  [8, 6]
Distance from 8 to 7 is : 7  [8, 7]
Distance from 8 to 8 is : 0  [8]

*/
