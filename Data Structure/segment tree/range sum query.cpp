/*
    * This includes range update
    * 1-based indexing (arr1, arr2, ..., arrN)
    * query(l,r) is inclusive of l and r 
    * function calls: query(1, 1, n, l, r) where 1 <= l,r <= n
*/

const int MAXN = 1e5 + 7;

struct NodeData
{
    int sum, lazy;
}tree[4 * MAXN];

int arr[MAXN];

void init()
{
    for (int i = 0; i < 4 * MAXN; i++)
        tree[i].sum = tree[i].lazy = 0;
}

void build(int node, int st, int ed)
{
    if(st == ed)
    {
        tree[node].sum = arr[st];
        return;
    }
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    build(left, st, mid);
    build(right, mid + 1, ed);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void setValue(int node, int st, int ed, int val)
{
    tree[node].sum += (ed - st + 1) * val;
    tree[node].lazy += val;
}

void propagate(int node, int st, int ed)
{
    if (tree[node].lazy == 0)
        return;
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    setValue(left, st, mid, tree[node].lazy);
    setValue(right, mid + 1, ed, tree[node].lazy);
    tree[node].lazy = 0;
}

void update(int node, int st, int ed, int i, int j, int val)
{
    if(st >= i && ed <= j)
    {
        setValue(node, st, ed, val);
        return;
    }
    if( i > ed || j < st)
        return;
    propagate(node, st, ed);
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    update(left, st, mid, i, j, val);
    update(right, mid+1, ed, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int st, int ed, int i, int j)
{
    if(st >= i && ed <= j)
        return tree[node].sum;
    if( i > ed || j < st)
        return 0;
    propagate(node, st, ed);
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    return query(left, st, mid, i, j) + query(right, mid+1, ed, i, j);
}