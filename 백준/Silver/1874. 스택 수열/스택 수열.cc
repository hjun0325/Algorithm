#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::vector<char> result;
	std::stack<int> stack;
	stack.push(0);
	int value = 0;
	int max = 0;
	
	int N;
	std::cin >> N;

	for (int i = 0;i < N;i++)
	{
		std::cin >> value;

		// 이전 max값보다 작은 경우.
		if (max > value)
		{
			// 탑에 있는 값과 같은 경우.
			if (stack.top() == value)
			{
				stack.pop();
				result.emplace_back('-');
			}
			// 탑에 있는 값과 다른 경우.
			else
			{
				std::cout << "NO";
				return 0;
			}
		}

		// 이전 max값보다 큰 경우.
		else
		{
			for (int j = max + 1; j <= value;j++)
			{
				stack.push(j);
				result.emplace_back('+');
			}
			stack.pop();
			result.emplace_back('-');
		}

		if (value > max)
		{
			max = value;
		}
	}

	for (int i = 0;i < result.size();i++)
	{
		std::cout << result[i] << "\n";
	}
}
