#include <iostream>

int N;
int M;
int list[8] = { 0 };
bool checked[8] = { false };

void BackTraking(int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; ++i)
		{
			std::cout << list[i]+1 << " ";
		}
		std::cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (checked[i] == false)
		{
			checked[i] = true;
			list[count] = i;
			BackTraking(count + 1);
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
	
	BackTraking(0);
}
