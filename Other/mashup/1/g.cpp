#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], b[maxn];

int solve ()
{
	int ans = 0;
	multiset < int > Set;
	multiset < int > :: iterator it;
	for (int i = 1; i <= n; ++i)
		Set.insert (b[i]);
	for (int i = 1; i <= n; ++i)
	{	
		it = Set.upper_bound (a[i]);
		if (it != Set.end())
		{
			++ans;
			Set.erase (it);	
		}
	}
	return ans;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &b[i]);
	printf ("%d\n", solve());
	return 0;
}
