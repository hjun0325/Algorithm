#include<iostream>
#include<list>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::string s;
	int num;
	char insertNum;

	std::cin >> s;
	std::cin >> num;

	std::list<char> l(s.begin(), s.end());
	std::list<char>::iterator it = l.end();

	for (int i = 0; i < num; ++i)
	{
		std::cin >> s;
		if (s == "L")
		{
			if (it != l.begin())
			{
				it--;
			}
		}
		else if (s == "D")
		{
			if (it != l.end())
			{
				it++;
			}
		}
		else if (s == "B")
		{
			if (it != l.begin())
			{
				l.erase(prev(it));
			}
		}
		else if (s == "P")
		{
			std::cin >> insertNum;
			l.insert(it, insertNum);
		}
	}

	for (char m : l)
	{
		std::cout << m;
	}

	return 0;
}