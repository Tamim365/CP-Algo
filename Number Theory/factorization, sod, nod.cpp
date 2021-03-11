vector <int> factors;

void factorize (int n)
{
    int sqrtn = sqrt(n);
    for(int i=0; i<prime.size() && prime[i] <= sqrtn; ++i)
    {
        if (sieve[n] == 0) break;
        if(n%prime[i] == 0)
        {
            while (n%prime[i] == 0)
            {
                n/=prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt (n);
        }
    }
    if (n != 1) factors.push_back(n);
}

int NOD ( int n )
{
    int sqrtn = sqrt (n);
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int p = 0; // Counter for power of prime
            while (n % prime[i] == 0) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt (n);
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 ) {
        res *= 2; // Remaining prime has power p^1. So multiply with 2
    }
    return res;
}

int SOD( int n )
{
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}

