#include <iostream>

int main()
{
	int T = 0;
	std::cin >> T;

	int length = 10000001;
	int* arr = new int[length] {};

	for (int i = 2;i <= length;++i) // 0은 소수 1은 소수x
	{
		if (i * i > length)
		{
			break;
		}

		if (arr[i] == 1)
		{
			continue;
		}

		for (int j = i + i;j < length;j += i)
		{
			arr[j] = 1;
		}
	}

	int n;
	int count = 0;
	while (T != 0)
	{
		std::cin >> n;

		for (int i = 2;i <= (n / 2);++i)
		{
			if (arr[i] == 0 && arr[n - i] == 0)
			{
				++count;
			}
		}

		std::cout << count << "\n";
		
		count = 0;
		--T;
	}
}