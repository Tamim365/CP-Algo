/*
    * used path compression and rank compression
    * Ref: https://cp-algorithms.com/data_structures/disjoint_set_union.html
*/

struct UnionFindDisjointSet
{
    vector<int> parent, rank;
    UnionFindDisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int i) {
        return (parent[i] == i) ? i : (parent[i] = find_set(parent[i]));
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    bool isSameSet(int i, int j) {
        return find_set(i) == find_set(j);
    }
};