/*
    * string hashing complexity O(n)
    * get_hash() function works in 0-based index of the string and inclusive of (i,j)
    * pair_hash for unordered_map or unordered_set
*/

#define     MP(x, y)        make_pair(x, y)
#define     ff 	            first
#define     ss 	            second
#define     ll              long long
#define     PII             pair<int, int>
#define     PLL             pair<ll, ll>
// #define     int             long long int

ostream& operator<<(ostream& os, PII hash) { return os << "(" << hash.ff << ", " << hash.ss << ")"; }

PII operator+ (PII a, int x) { return MP(a.ff + x, a.ss + x); }
PII operator- (PII a, int x) { return MP(a.ff - x, a.ss - x); }
PII operator* (PII a, int x) { return MP(a.ff * x, a.ss * x); }
PII operator+ (PII a, PII x) { return MP(a.ff + x.ff, a.ss + x.ss); }
PII operator- (PII a, PII x) { return MP(a.ff - x.ff, a.ss - x.ss); }
PII operator* (PII a, PII x) { return MP(a.ff * x.ff, a.ss * x.ss); }
PII operator% (PII a, PII m) { return MP(a.ff % m.ff, a.ss % m.ss); }


struct HashTable
{
    PII base, mod;
    int N;
	vector<PII> pw, hashes, inv;
	HashTable(PII p, PII m, int n)
	{
		base = p;
		mod = m;
		N = n;
		pw.resize(n);
		hashes.resize(n);
		inv.resize(n);
		pre();
	}
	PII add(PII a, PII b, PII m)
	{
		PII res = (a % m + b % m) % m;
		if (res.ff < 0) res.ff += m.ff;
		if (res.ss < 0) res.ss += m.ss;
		return res;
	}
    int mul(int a, int b, int m)
    {
        int res = (a%m * 1LL * b%m) % m;
        if(res < 0) res += m;
        return res;
    }
	PII mul(PII a, PII b, PII m) { return {mul(a.ff, b.ff, m.ff), mul(a.ss, b.ss, m.ss)}; }
	int bigmod(int p, int e, int M)
	{
		int ret = 1;
		for (; e > 0; e >>= 1) { if (e & 1) ret = mul(ret, p, M); p = mul(p, p, M); }
		return ret;
	}
	void pre()
	{
		pw[0] = {1, 1};
		for (int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], base, mod);
		PII pw_inv = {bigmod(base.ff, mod.ff - 2, mod.ff), bigmod(base.ss, mod.ss - 2, mod.ss)};
		inv[0] = {1, 1};
		for (int i = 1; i < N; i++) inv[i] = mul(inv[i - 1], pw_inv, mod);
	}
	void build(string s)
	{
		int len = s.size();
		hashes[0] = mul({s[0] - 'a' + 1, s[0] - 'a' + 1}, pw[0], mod);
		for (int i = 1; i < len; i++)
			hashes[i] = add(hashes[i - 1], mul({s[i] - 'a' + 1, s[i] - 'a' + 1}, pw[i], mod), mod);
	}
	PII getHash(int i, int j)
	{
		PII res = add(hashes[j], (i == 0) ? MP(0, 0) : MP(0,0)-hashes[i - 1], mod);
		res = mul(res, inv[i], mod);
		return res;
	}
	void printHash(int n)
	{
		for (int i = 0; i < n; i++)
			cout << hashes[i] << " ";
		cout << endl;
	}
};

string gen_substr(string s, int x, int y)
{
	string ret = "";
	int i;
	for (i = x; i <= y; i++) ret += s[i];
	return ret;
}

struct pair_hash {
	inline std::size_t operator()(const std::pair<int, int> & v) const {
		return v.first * 93 + v.second;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	read;
	write;
#endif
	fast;
    PII base = {31, 67}, mod = {79791713, 34691837};
    int max_n = 1e6 + 7;
    HashTable ht(base, mod, max_n);
    string s; cin >> s;
    ht.build(s);
}