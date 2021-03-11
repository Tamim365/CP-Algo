template < class T > inline T gcd(T a, T b) {while(b) { a %= b; swap(a, b); } return a;}
template < class T > inline T lcm(T a, T b) { return (T) (a / gcd(a, b)) * b; }
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
/** The Fastest mulmod **/
long long int mulmod(long long int a,long long int b, long long MOD) {
   long double res = a;
   res *= b;
   long long int c = (long long)(res / MOD);
   a *= b;
   a -= c * MOD;
   a %= MOD;
   if (a < 0) a += MOD;
   return a;
}
/** The Fastest mulmod **/

