#include <iostream>

int N;
int M;
int list[9] = { 0 };
bool checked[9] = { false };

void BackTraking(int number, int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; ++i)
		{
			std::cout << list[i] << " ";
		}
		std::cout << "\n";
		return;
	}

	for (int i = number; i <= N; ++i)
	{
		if (checked[i] == false)
		{
			checked[i] = true;
			list[count] = i;
			BackTraking(i + 1, count + 1);
			checked[i] = false;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	
	BackTraking(1, 0);
}