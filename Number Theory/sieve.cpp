vector<int> Sieve(int n)
{
    vector<int> prime;
    bool mark[n+1];
    memset(mark, true, sizeof(mark));
    for (int p=2; p*p<=n; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                mark[i] = false;
        }
    }
    for (int i=2; i<=n; i++)
        if (mark[i])
            prime.pb(i);
    return prime;
}
