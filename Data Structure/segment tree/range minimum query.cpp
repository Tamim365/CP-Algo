/*
    * This includes no update
    * 1-based indexing (arr1, arr2, ..., arrN)
    * query(l,r) is inclusive of l and r 
    * function calls: query(1, 1, n, l, r) where 1 <= l,r <= n
*/

const int MAXN = 1e5 + 7;

int tree[4 * MAXN];
int arr[MAXN];

void build(int node, int st, int ed)
{
    if(st > ed) return;
    if(st == ed)
    {
        tree[node] = arr[st];
        return;
    }
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    build(left, st, mid);
    build(right, mid + 1, ed);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int st, int ed, int i, int j)
{
    if(st >= i && ed <= j)
        return tree[node];
    if( i > ed || j < st)
        return INT_MAX;
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    return min(query(left, st, mid, i, j), query(right, mid+1, ed, i, j));
}