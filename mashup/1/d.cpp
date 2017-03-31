#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

long long n, f, e[maxn];
long long a, b, c;

set < int > t[maxn];
set < int > :: iterator it;

int pos[maxn];

int main ()
{
	scanf ("%lld %lld", &n, &f);
	
	scanf ("%lld %lld %lld", &a, &b, &c);
	
	msmet (pos, -1, sizeof (pos));
	
	e[1] = a;
	t[e[1]].insert(1);
	pos[1] = e[1];
	
	for (int i = 2; i <= n; ++i)
	{
		e[i] = (b * e[i - 1] + c) % f;
		t[e[i]].insert(i);
		pos[i] = e[i];
	}
	
	int m;
	scanf ("%d", &m);
	
	while (m--)
	{
		int E, I;
		scanf ("%d %d", &E, &I);
		
		if (pos[I] != -1)
			t[pos[I]].erase(I);
			
		pos[I] = E;
		
		if (t[E].empty())
		{
			printf ("%lld %lld\n", n, n);
			t[E].insert(I);
			continue;
		}
		
		long long l = -1, r = -1;
		
		t[E].insert(I);
		
		it = t[E].find(I);
		++it;
		
		if (it == t[E].end())
			r = I - *t[E].begin();
		else
			r = *it - I;
			
		it = t[E].find(I);
		
		if (it == t[E].begin())
		{
			--it;
			l = I - *it;
		}
		else
			l = *(--t[E].end()) - I;
		
		printf ("%lld %lld\n", l, r);
	}
	
	return 0;
}
