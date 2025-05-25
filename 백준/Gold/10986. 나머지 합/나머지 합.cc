#include <iostream>

// N개의 수를 저장하는 베열.
int arr[1000001];

// M으로 나누었을때 나머지를 저장하는 배열
long long int marr[1001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	long long int result = 0;

	for (int i = 1;i <= N;i++)
	{
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
		arr[i] %= M;
	} 

	for (int i = 1;i <= N;i++)
	{
		if (arr[i] >= 0)
		{
			marr[arr[i]]++;
		}
	}

	result += marr[0];
	for (int i = 0;i < M;i++)
	{
		result += (marr[i] * (marr[i] - 1)) / 2;
	}

	std::cout << result;
}