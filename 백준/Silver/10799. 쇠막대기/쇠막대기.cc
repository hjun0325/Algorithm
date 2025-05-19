#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;

	int numStack = 0;
	int result = 0;
	
	for (int i = 0;i < str.length();i++)
	{
		// '('일 경우.
		if (str[i] == '(')
		{
			// 막대기가 하나 더 늘었으므로 스택에 추가.
			numStack += 1;
		}

		// ')'일 경우.
		else
		{
			// 레이저인 경우.
			if (str[i - 1] == '(')
			{
				// 앞선 '('가 막대기 추가가 아닌 레이저이므로 스택에서 하나 빼기
				numStack -= 1;
				result += numStack;
			}

			// 막대기의 끝인 경우.
			else
			{
				numStack -= 1;
				result += 1;
			}
		}
	}

	std::cout << result;
}