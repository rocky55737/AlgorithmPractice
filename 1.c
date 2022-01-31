#include <stdio.h>

int main()
{
	int N = 0, K = 0;
	int i, c = 0;

	scanf("%d %d", &N, &K);
	if (N >= 1 && N <= 10000 && K >= 1 && K <= N)
	{
		for (i = 1; ((i <= N) && (c < K)); i++)
			if (N % i == 0)	c++;
		if (c == K)
			printf("%d", (i - 1));
		else
			printf("%d", -1);
		return (0);
	}
	else
		printf("%d", -1);
}