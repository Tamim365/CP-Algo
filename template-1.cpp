#include<bits/stdc++.h>
using namespace std;
 
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     READ            freopen("input.txt","r",stdin)
#define     WRITE           freopen("output.txt","w",stdout)
#define     D(x)            cout << '>' << #x << ':' << x << endl
#define     rep(i,k,n)      for(int i=k;i<n;i++)

#define     UI              unsigned int
#define     LL              long long int
#define     LD              long double
#define     ULL             unsigned long long int
#define     VI              vector<int>
#define     PII             pair<int,int>
#define     VB              vector<bool>
#define     VLD             vector<LD>
#define     VLL             vector<LL>
#define     VULL            vector<ULL>
#define     VVI             vector<VI>

#define     MP(x, y)        make_pair(x, y)
#define     PB(x)           push_back(x)
#define     ALL(p)          p.begin(),p.end()
#define     CLR(p)          memset(p, 0, sizeof(p))
#define     MEM(a, b)       memset(a, (b), sizeof(a))
#define     ff              first
#define     ss              second

inline void IN(int &a) { scanf("%d", &a); }
inline void IN(LL &a) { scanf("%lld", &a); }
inline void IN(ULL &a) { scanf("%llu", &a); }
inline void IN(char *a) { scanf("%s", a); }
inline void IN(LD &a) { cin >> a; }
inline void IN(string &a) { cin >> a; }
inline void IN(double &a) { cin >> a; }
inline void IN(bool &a) { int aa; IN(aa); a = aa; }
template<typename T1, typename T2> inline void IN(pair<T1, T2> &a) { IN(a.ff); IN(a.ss); }
template<typename T> inline void IN(vector<T> &a) { for (T &aa : a) IN(aa); }
template<typename T, typename... Args> inline void IN(T &a, Args &... args) { IN(a); IN(args...); }

inline void OUT(const int &a) { printf("%d", a); }
inline void OUT(const LL &a) { printf("%lld", a); }
inline void OUT(const ULL &a) { printf("%llu", a); }
inline void OUT(const char *a) { printf("%s", a); }
inline void OUT(const char &a) { printf("%c", a); }
inline void OUT(const string &a) { for (const char &aa : a) OUT(aa); }
inline void OUT(const bool &a) { printf("%d", a); }
template<typename T1, typename T2> inline void OUT(const pair<T1, T2> &a) { OUT("{"); OUT(a.ff); OUT(", "); OUT(a.ss); OUT("}"); }
template<typename T> inline void OUT(const T &a) { int i = 0; OUT("{"); for (const auto &aa : a) { if (i++) OUT(", "); OUT(aa); } OUT("}"); }
template<typename T, typename... Args> inline void OUT(const T &a, const Args &... args) { OUT(a); OUT(" "); OUT(args...); }
template<typename... Args> inline void O(const Args &... args) { OUT(args...); OUT("\n"); }

template < typename T > inline T power(T p, T e, T M){ T ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T)ret; }
template < typename T > inline T power(T p, T e){ T ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p); p = (p * p); } return (T)ret; }

#ifndef ONLINE_JUDGE
#define debug(args...) { string _s = "[" + string(#args) + "] = ["; OUT(_s); deb(args); }
void deb() {}
template<typename T, typename... Args>
void deb(T a, Args... args) {
OUT(a), OUT((sizeof...(args) ? ", " : "]\n"));
deb(args...);
}
#else
    #define debug(args...)
#endif

const double    PI=acos(-1.0);
const double    EPS = 1e-9;
const int       MOD = 1e9+7;
const int       MAXN = 1e6+3;


signed main() {
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif
    
    return 0;
}