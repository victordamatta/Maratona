#include <bits/stdc++.h>
using namespace std;

double a[15];
double soma;
int n;

bool solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		bool OK = true;

		for (int j = 1; j <= n; ++j)
			if (i != j && a[j] >= a[i])
				OK = false;

		if (!OK)
			continue;

		if (a[i]/soma >= 0.45)
			return true;
		
		if (a[i]/soma >= 0.40)
		{
			double cmp = soma / 10;

			bool ok = true;
			
			for (int j = 1; j <= n; ++j)
				if (i != j && a[j] + cmp > a[i])
					ok = false;	

			if (ok)
				return true;
		}
	}
	return false;
}

int main ()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		soma += a[i];
	}

	if (solve())
		cout << "1\n";
	else
		cout << "2\n";

	return 0;
}
