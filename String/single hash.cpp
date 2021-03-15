/*
    * string hashing complexity O(n)
    * after hashing, can check palindrome or sub-palindrome in O(1)
    * check_palindrome() and get_hash() function works in 0-based index of the string and inclusive of (i,j)
*/

struct HashTable
{
    int base, mod, N;
    vector<int> pw, hashes, inv, rev_hashes;
    HashTable(int p, int m, int n)
    {
        base = p;
        mod = m;
        N = n;
        pw.resize(n);
        hashes.resize(n);
        inv.resize(n);
        rev_hashes.resize(n);
        pre();
    }
    inline int add(int a, int b, int m)
    {
        int res = (a%m + b%m) % m;
        if(res < 0) res += m;
        return res;
    }
    inline int mul(int a, int b, int m)
    {
        int res = (a%m * 1LL * b%m) % m;
        if(res < 0) res += m;
        return res;
    }
    int bigmod(int p, int e, int M)
    {
        int ret = 1;
        for(; e > 0; e >>= 1){ if(e & 1) ret = mul(ret, p, M); p = mul(p, p, M); }
        return ret;
    }
    void pre()
    {
        pw[0] = 1;
        for(int i = 1; i < N; i++) pw[i] = mul(pw[i-1], base, mod);
        int pw_inv = bigmod(base, mod - 2, mod);
        inv[0] = 1;
        for(int i = 1; i < N; i++) inv[i] = mul(inv[i-1], pw_inv, mod);
    }
    void build(string s)
    {
        int len = s.size();
        hashes[0] = mul(s[0]-'a'+1, pw[0], mod);
        for(int i = 1; i < len; i++)
            hashes[i] = add(hashes[i-1], mul(s[i]-'a'+1, pw[i], mod), mod);
    }
    void rev_build(string s)
    {
        reverse(s.begin(), s.end());
        int len = s.size();
        rev_hashes[0] = mul(s[0]-'a'+1, pw[0], mod);
        for(int i = 1; i < len; i++)
            rev_hashes[i] = add(rev_hashes[i-1], mul(s[i]-'a'+1, pw[i], mod), mod);
    }
    int getHash(int i, int j)
    {
        int res = add(hashes[j], (i==0) ? 0 : -hashes[i-1], mod);
        res = mul(res, inv[i], mod);
        return res;
    }
    int getRevHash(int i, int j)
    {
        int res = add(rev_hashes[j], (i==0) ? 0 : -rev_hashes[i-1], mod);
        res = mul(res, inv[i], mod);
        return res;
    }
    int check_palindrome(int i, int j, int n)
    {
        if(getHash(i, j) == getRevHash(n-j-1, n-i-1)) return 1;
        return 0;
    }
};

string gen_substr(string s, int x, int y)
{
    string ret = "";
    int i;
    for(i = x; i<=y; i++) ret += s[i];
    ret += '\0';
    return ret;
}

int primes[] = {146793191, 124436047, 113476073, 131421109, 177900407, 122650169, 162692791, 111302981, 112501897, 132201799};

signed main()
{
    srand(time(0));
    int base = 300, mod = primes[rand()%10], max_n = 1e5+7;
    HashTable ht(base, mod, max_n);
    string s; cin >> s;
    ht.build(s);
    ht.rev_build(s);
}