bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

int status[(mx/32)+2];
vector<int> sieve()
{
	int i, j, sqrtN; 
	sqrtN = int(sqrt(N));
	for(i = 3; i <= sqrtN; i += 2) 
	{
		if(Check(status[i>>5],i&31)==0)
		{
			for(j = i*i; j <= N; j += (i<<1))
			{
				status[j>>5]=Set(status[j>>5],j & 31);
			}
		}
	}
	vector<int> prime;
	prime.push_back(2);
	for(i=3;i<=N;i+=2)
		if( Check(status[i>>5],i&31)==0)
			prime.push_back(i);
	return prime;
}