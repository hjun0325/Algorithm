#include<iostream>
#include<queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	int pushNum;
	std::string s;
	std::queue<int> q;

	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> s;
		
		if ("push" == s)
		{
			std::cin >> pushNum;
			q.push(pushNum);
		}
		else if ("pop" == s)
		{
			if (q.empty() == true)
			{
				std::cout << "-1" << "\n";
				continue;
			}
			std::cout << q.front() << "\n";
			q.pop();
		}
		else if ("size" == s)
		{
			std::cout << q.size() << "\n";
		}
		else if ("empty" == s)
		{
			std::cout << q.empty() << "\n";
		}
		else if ("front" == s)
		{
			if (q.empty() == true)
			{
				std::cout << "-1" << "\n";
				continue;
			}
			std::cout << q.front() << "\n";
		}
		else if ("back" == s)
		{
			if (q.empty() == true)
			{
				std::cout << "-1" << "\n";
				continue;
			}
			std::cout << q.back() << "\n";
		}
	}


	return 0;
}