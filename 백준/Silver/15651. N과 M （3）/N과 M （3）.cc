#include <iostream>

int N;
int M;
int list[8] = { 0 };

void BackTraking(int count)
{
	if (count == M + 1)
	{
		for (int i = 1; i <= M; ++i)
		{
			std::cout << list[i] << " ";
		}
		std::cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		list[count] = i;
		BackTraking(count + 1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	
	BackTraking(1);
}
