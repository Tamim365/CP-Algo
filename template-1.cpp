#include<bits/stdc++.h>
using namespace std;
 
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     D(x)            cout << '>' << #x << ':' << x << endl
#define     rep(i,k,n)      for(int i=k;i<n;i++)

#define     ll              long long int
#define     ull             unsigned long long int
#define     UI              unsigned int
#define     LD              long double
#define     VI              vector<int>
#define     VLL             vector<ll>
#define     VB              vector<bool>
#define     VLD             vector<LD>
#define     VULL            vector<ull>
#define     VVI             vector<VI>
#define     PII             pair<int, int>

#define     MP(x, y)        make_pair(x, y)
#define     PB(x)           push_back(x)
#define     ALL(p)          p.begin(),p.end()
#define     CLR(p)          memset(p, 0, sizeof(p))
#define     MEM(a, b)       memset(a, (b), sizeof(a))
#define     ff              first
#define     ss              second

inline void sc(int &a) { scanf("%d", &a); }
inline void sc(ll &a) { scanf("%lld", &a); }
inline void sc(ull &a) { scanf("%llu", &a); }
inline void sc(char *a) { scanf("%s", a); }
inline void sc(LD &a) { cin >> a; }
inline void sc(string &a) { cin >> a; }
inline void sc(double &a) { cin >> a; }
inline void sc(bool &a) { int aa; sc(aa); a = aa; }
template<typename T1, typename T2> inline void sc(pair<T1, T2> &a) { sc(a.ff); sc(a.ss); }
template<typename T> inline void sc(vector<T> &a) { for (T &aa : a) sc(aa); }
template<typename T, typename... Args> inline void sc(T &a, Args &... args) { sc(a); sc(args...); }

inline void print(const int &a) { printf("%d", a); }
inline void print(const ll &a) { printf("%lld", a); }
inline void print(const ull &a) { printf("%llu", a); }
inline void print(const char *a) { printf("%s", a); }
inline void print(const char &a) { printf("%c", a); }
inline void print(const string &a) { for (const char &aa : a) print(aa); }
inline void print(const bool &a) { printf("%d", a); }
template<typename T1, typename T2> inline void print(const pair<T1, T2> &a) { print("{"); print(a.ff); print(", "); print(a.ss); print("}"); }
template<typename T> inline void print(const T &a) { int i = 0; print("{"); for (const auto &aa : a) { if (i++) print(", "); print(aa); } print("}"); }
template<typename T, typename... Args> inline void print(const T &a, const Args &... args) { print(a); print(" "); print(args...); }
template<typename... Args> inline void O(const Args &... args) { print(args...); print("\n"); }

template < typename T > inline T power(T p, T e, T M){ T ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T)ret; }
template < typename T > inline T power(T p, T e){ T ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p); p = (p * p); } return (T)ret; }

#ifndef ONLINE_JUDGE
#define debug(args...) { string _s = "[" + string(#args) + "] = ["; print(_s); deb(args); }
void deb() {}
template<typename T, typename... Args>
void deb(T a, Args... args) {
print(a), print((sizeof...(args) ? ", " : "]\n"));
deb(args...);
}
#else
    #define debug(args...)
#endif

const double    PI = acos(-1.0);
const double    EPS = 1e-9;
const int       MOD = 1e9+7;
const int       MAXN = 1e5+7;

signed main() {
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    
}