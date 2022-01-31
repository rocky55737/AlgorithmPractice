#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K;
	int* answer, *data;
	int ai = 0, ansize, temp;

	scanf("%d %d", &N, &K);
	if (N < 3 || N > 100 || K < 1 || K > 50)
			return (0);
	data = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &data[i]);
	ansize = (((N) * (N - 1) * (N - 2)) / 6);
	answer = (int*)malloc(sizeof(int) * ansize);
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
				answer[ai++] = data[i] + data[j] + data[k];
		}
	}
	for (int i = 0; i < ansize - 1; i++)
	{
		for (int j = 0; j < ansize - i - 1; j++)
		{
			if (answer[j] > answer[j + 1])
			{
				temp = answer[j];
				answer[j] = answer[j + 1];
				answer[j + 1] = temp;
			}
		}
	}
	printf("%d", answer[ansize - K]);
}