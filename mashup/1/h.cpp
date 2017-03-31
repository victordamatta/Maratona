#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

int a, b, k;

int soma[maxn];
int dp[maxn];

const int LOG = 60;
int sum[LOG][maxn];

void sieve ()
{
	for (int i = 2; i < maxn; ++i)
		if (!soma[i])
			for (int j = i + i; j < maxn; j += i)
				soma[j] += i;

	for (int i = 2; i < maxn; i++)
		if (soma[i])
			dp[i] = dp[soma[i]] + 1;
		else
			dp[i] = 1;
	
	for (int i = 2; i < maxn; ++i)
		for (int j = 1; j < LOG; ++j)
		{
			sum[j][i] += sum[j][i - 1];
			if (dp[i] == j)
				++sum[j][i];
		}
}

int main ()
{	
	int t;
	scanf ("%d", &t);
	sieve();
	while (t--)
	{
		scanf ("%d %d %d", &a, &b, &k);
		if (k >= LOG)
		{
			printf ("0\n");
			continue;
		}	
		printf ("%d\n", sum[k][b] - sum[k][a - 1]);
	}
	return 0;
}
