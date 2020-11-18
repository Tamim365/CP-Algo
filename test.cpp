#include<bits/stdc++.h>
using namespace std;

#define     rep(i,k,n)      for(long long int i=k;i<n;i++)
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     D(x)            cout << '>' << #x << ':' << x << endl
#define     DD(x,y)         cout << '>' << #x << ':' << x << ' ' << #y << ':' << y << endl
#define     DDD(x,y,z)      cout << '>' << #x << ':' << x << ' ' << #y << ':' << y << ' ' << #z << ':' << z << endl
#define     PI              acos(-1)
#define     MP(x, y)        make_pair(x, y)
#define     PB(x)           push_back(x)
#define     ALL(p)          p.begin(),p.end()
#define     CLR(p)          memset(p, 0, sizeof(p))
#define     MEM(a, b)       memset(a, (b), sizeof(a))
#define     ff 	            first
#define     ss 	            second
#define     sf              scanf
#define     pf              printf
#define     PII             pair<int, int>
#define     ll              long long int
#define     ull             unsigned long long int

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template < class T > inline T gcd(T a, T b) {while(b) { a %= b; swap(a, b); } return a;}
template < class T > inline T bigmod(T p, T e, T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; }
    return (T)ret;
}
template < class T > inline T power(T a, T n) {
    if(n==0) return 1;
    if(n==1) return a;
    T R = power(a,n/2);
    return (n%2==0) ? R*R : R*a*R;
}

int fx4[] = {0, 0, -1, +1};
int fy4[] = {+1, -1, 0, 0};
int fx8[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int fy8[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int fx8Knight[] = {+2, +2, +1, -1, -2, -2, -1, +1};
int fy8Knight[] = {+1, -1, -2, -2, -1, +1, +2, +2};

const int MAXN = 1e5+3;

void permutation(string s, int i, int j)
{
    if(i==j)
        cout << s << endl;
    else
    {
        for (int k = i; k <= j; k++)
        {
            swap(s[k], s[j]);
            permutation(s, i + 1, j);
            swap(s[k], s[j]);
        }
        
    }
}

void permutation(string s)
{
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main() {
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    fast;
    string s = "ABC";
    permutation(s);
    return 0;
}