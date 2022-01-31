#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T;
	int N, s, e, k;
	int* data, *answer;
	int temp;

	scanf("%d", &T);
	if (T < 1 || T > 10)
		return (0);
	answer = (int*)malloc(sizeof(int) * T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d %d %d", &N, &s, &e, &k);
		if (N < 5 || N > 500)
			return (0);
		data = (int*)malloc(sizeof(int) * N);
		for (int dc = 0; dc < N; dc++)
			scanf("%d", &data[dc]);
		for (int c = s - 1; c < e; c++)
		{
			for (int cc = s - 1; cc <= e - c; cc++)
			{
				if (data[cc] > data[cc + 1])
				{
					temp = data[cc];
					data[cc] = data[cc + 1];
					data[cc + 1] = temp;
				}
			}
		}
		answer[tc] = data[s + k - 2];
		free(data);
	}
	for (int tc = 0; tc < T; tc++)
		printf("#%d %d\n", tc + 1, answer[tc]);
	free(answer);
}