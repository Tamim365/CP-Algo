/*
    * This includes no update
    * 1-based indexing (arr1, arr2, ..., arrN)
    * query(l,r) is inclusive of l and r 
    * function calls: query(1, 1, n, l, r) where 1 <= l,r <= n
    * problem link: https://www.spoj.com/problems/GSS3/en/
*/

#define     int              ll

const int MAXN = 2e5 + 7;

struct NodeData
{
    int total, suffix, prefix, max_sum;
}tree[4 * MAXN];

int arr[MAXN];

void init()
{
    for (int i = 0; i < 4 * MAXN; i++)
        tree[i].total = tree[i].max_sum = tree[i].suffix = tree[i].prefix = 0;
}

void merge(int node, int st, int ed)
{
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    tree[node].total = tree[left].total + tree[right].total;
    tree[node].prefix = max(tree[left].total + tree[right].prefix, max(tree[left].total, tree[left].prefix));
    tree[node].suffix = max(tree[left].suffix + tree[right].total, max(tree[right].suffix, tree[right].total));
    tree[node].max_sum = max(tree[left].max_sum, tree[right].max_sum);
    tree[node].max_sum = max(tree[node].max_sum, tree[right].prefix + tree[left].suffix);
    tree[node].max_sum = max(tree[node].max_sum, tree[node].total);
    tree[node].max_sum = max(tree[node].max_sum, tree[node].prefix);
    tree[node].max_sum = max(tree[node].max_sum, tree[node].suffix);
}

void build(int node, int st, int ed)
{
    if(st == ed)
    {
        tree[node].suffix = arr[st];
        tree[node].prefix = arr[st];
        tree[node].total = arr[st];
        tree[node].max_sum = arr[st];
        return;
    }
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    build(left, st, mid);
    build(right, mid + 1, ed);
    merge(node, st, ed);
}


void update(int node, int st, int ed, int i, int val)
{
    if(st == ed)
    {
        tree[node].suffix = val;
        tree[node].prefix = val;
        tree[node].total = val;
        tree[node].max_sum = val;
        return;
    }
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    if(i <= mid) update(left, st, mid, i, val);
    else update(right, mid+1, ed, i, val);
    merge(node, st, ed);
}

NodeData findMAX(NodeData d1, NodeData d2)
{
    int total, prefix, suffix, max_sum;
    total = d1.total + d2.total;
    prefix = max(d1.total + d2.prefix, max(d1.total, d1.prefix));
    suffix = max(d1.suffix + d2.total, max(d2.suffix, d2.total));
    max_sum = max(d1.max_sum, d2.max_sum);
    max_sum = max(max_sum, d2.prefix + d1.suffix);
    max_sum = max(max_sum, total);
    max_sum = max(max_sum, prefix);
    max_sum = max(max_sum, suffix);
    NodeData ret;
    ret.total = total;
    ret.prefix = prefix;
    ret.suffix = suffix;
    ret.max_sum = max_sum;
    return ret;
}

NodeData query(int node, int st, int ed, int i, int j)
{
    if(st >= i && ed <= j)
    {
        return tree[node]; 
    }
    if( i > ed || j < st)
    {
        NodeData ret;
        ret.total = MAXN * INT_MIN;
        ret.prefix = MAXN * INT_MIN;
        ret.suffix = MAXN * INT_MIN;
        ret.max_sum = MAXN * INT_MIN;
        return ret;
    }
    int left = 2 * node, right = 2 * node + 1, mid = (st + ed) / 2;
    NodeData d1 = query(left, st, mid, i, j);
    NodeData d2 = query(right, mid + 1, ed, i, j);
    return findMAX(d1, d2);
}