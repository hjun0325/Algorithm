#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int s;
	int p;

	std::string str;

	std::cin >> s >> p;
	std::cin >> str;

	int a, c, g, t;
	std::cin >> a >> c >> g >> t;

	int result = 0;

	int a1 = 0, c1 = 0, g1 = 0, t1 = 0;
	int start, end;

	for (int j = 0;j < p;j++)
	{
		if (str[j] == 'A')
		{
			a1++;
		}
		else if (str[j] == 'C')
		{
			c1++;
		}
		else if (str[j] == 'G')
		{
			g1++;
		}
		else if (str[j] == 'T')
		{
			t1++;
		}
	}

	if (a1 >= a && c1 >= c && g1 >= g && t1 >= t)
	{
		result++;
	}

	for (int i = 0;i < (s - p);i++)
	{
		start = i, end = i + p;

		if (str[start] == 'A')
		{
			a1--;
		}
		else if (str[start] == 'C')
		{
			c1--;
		}
		else if (str[start] == 'G')
		{
			g1--;
		}
		else if (str[start] == 'T')
		{
			t1--;
		}

		if (str[end] == 'A')
		{
			a1++;
		}
		else if (str[end] == 'C')
		{
			c1++;
		}
		else if (str[end] == 'G')
		{
			g1++;
		}
		else if (str[end] == 'T')
		{
			t1++;
		}

		if (a1 >= a && c1 >= c && g1 >= g && t1 >= t)
		{
			result++;
		}
	}
	std::cout << result;
}