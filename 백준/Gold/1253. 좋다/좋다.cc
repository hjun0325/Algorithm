#include <iostream>
#include <algorithm>

int arr[2000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N;i++)
	{
		std::cin >> arr[i];
	}
	std::sort(arr, arr + N);

	int result = 0;
	int first = 0;
	int last = N - 1;

	for (int i = 0;i < N;i++)
	{
		first = 0;
		last = N - 1;
		while (first < last)
		{
			// 양쪽 값의 합이 더 크다면 last값을 줄인다.
			if (arr[first] + arr[last] > arr[i] || last == i)
			{
				last--;
			}
			// 양쪽 값의 합이 더 작다면 first값을 늘린다.
			else if (arr[first] + arr[last] < arr[i] || first == i)
			{
				first++;
			}
			// 같으면 result 값 증가.
			else
			{
				result++;
				break;
			}
		}
	}

	std::cout << result;
}